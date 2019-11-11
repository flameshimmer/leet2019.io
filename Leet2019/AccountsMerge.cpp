#include "stdafx.h"

//Given a list accounts, each element accounts[i] is a list of strings, where the
//first element accounts[i][0] is a name, and the rest of the elements are emails
//representing emails of the account.
//Now, we would like to merge these accounts. Two accounts definitely belong to
//the same person if there is some email that is common to both accounts. 
//Note
//that even if two accounts have the same name, they may belong to different
//people as people could have the same name. A person can have any number of
//accounts initially, but all of their accounts definitely have the same name.
//After merging the accounts, return the accounts in the following format: the
//first element of each account is the name, and the rest of the elements are
//emails in sorted order. The accounts themselves can be returned in any order.
//
//Example 1:
//Input: 
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
//"johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
//"john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
//Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
//'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
//"mary@mail.com"]]
//Explanation: 
//The first and third John's are the same person as they have the common email
//"johnsmith@mail.com".
//The second John and Mary are different people as none of their email addresses
//are used by other accounts.
//We could return these lists in any order, for example the answer [['Mary',
//'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
//['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
//would still be accepted.
//
//Note:
//The length of accounts will be in the range [1, 1000].
//The length of accounts[i] will be in the range [1, 10].
//The length of accounts[i][j] will be in the range [1, 30].

namespace Solution2019
{
	namespace AccountsMerge
	{
		namespace MySolution {
			int find(int i, vector<int>& parents) {
				if (parents[i] == i) { return i; }
				return find(parents[i], parents);
			}

			vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
				vector<vector<string>> results;
				int len = accounts.size();
				if (len == 0) { return results; }

				vector<int> parents(len);
				for (int i = 0; i < len; i++) { parents[i] = i; }

				unordered_map<string, vector<int>> map;
				for (int i = 0; i < len; i++) {
					vector<string>& acc = accounts[i];
					for (int j = 1; j < acc.size(); j++) {
						map[acc[j]].push_back(i);
					}
				}

				for (auto& p : map) {
					vector<int>& group = p.second;
					int p0 = find(group[0], parents);
					for (int i = 1; i < group.size(); i++) {
						int p = find(group[i], parents);
						if (p != p0) {
							parents[p] = p0;
						}
					}
				}

				unordered_map<int, vector<int>> groups;
				for (int i = 0; i < len; i++) {
					int p = find(i, parents);
					groups[p].push_back(i);
				}

				for (auto& p : groups) {
					int i = p.first;
					vector<string> result = { accounts[i][0] };
					set<string> emails;
					for (int j : p.second) {
						for (int k = 1; k < accounts[j].size(); k++) {
							emails.insert(accounts[j][k]);
						}
					}
					for (string e : emails) {
						result.push_back(e);
					}
					results.push_back(result);
				}
				return results;
			}

			namespace SlowerButShorter {
				string find(string& s, map<string, string>& parents) {
					if (parents[s] == s) { return s; }
					return find(parents[s], parents);
				}

				vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
					map<string, string> owner;
					map<string, string> parents;
					map<string, set<string>> unions;

					int len = accounts.size();
					for (int i = 0; i < len; i++) {
						vector<string>& acc = accounts[i];
						for (int j = 1; j < acc.size(); j++) {
							parents[acc[j]] = acc[j];
							owner[acc[j]] = acc[0];
						}
					}

					for (int i = 0; i < len; i++) {
						vector<string>& acc = accounts[i];
						string p = find(acc[1], parents);
						for (int j = 2; j < acc.size(); j++) {
							parents[find(acc[j], parents)] = p;
						}
					}

					for (int i = 0; i < len; i++) {
						vector<string>& acc = accounts[i];
						for (int j = 1; j < acc.size(); j++) {
							unions[find(acc[j], parents)].insert(acc[j]);
						}
					}

					vector<vector<string>> results;
					for (auto& p : unions) {
						vector<string> result(p.second.begin(), p.second.end());
						result.insert(result.begin(), owner[p.first]);
						results.push_back(result);
					}
					return results;
				}
			}

		}

		void Main() {
			vector<vector<string>> test = { {"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"} };
			print(MySolution::accountsMerge(test));
		}
	}
}

