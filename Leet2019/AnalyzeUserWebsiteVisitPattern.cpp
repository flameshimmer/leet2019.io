#include "stdafx.h"
//We are given some website visits: the user with name
//username[i] visited the website website[i] at time 
//timestamp[i].
//
//A 3-sequence is a list of websites of length 3 sorted 
//in ascending order by the time of their visits.  
//(The websites in a 3-sequence are not necessarily distinct.)
//
//Find the 3-sequence visited by the largest number of 
//users. If there is more than one solution, return 
//the lexicographically smallest such 3-sequence.
//
// 
//
//Example 1:
//
//Input: 
//username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], 
//timestamp = [1,2,3,4,5,6,7,8,9,10], 
//website = ["home","about","career","home","cart","maps","home","home","about","career"]
//Output: ["home","about","career"]
//Explanation: 
//The tuples in this example are:
//["joe", 1, "home"]
//["joe", 2, "about"]
//["joe", 3, "career"]
//["james", 4, "home"]
//["james", 5, "cart"]
//["james", 6, "maps"]
//["james", 7, "home"]
//["mary", 8, "home"]
//["mary", 9, "about"]
//["mary", 10, "career"]
//The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
//The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
//The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
//The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
//The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
// 
//
//Note:
//3 <= N = username.length = timestamp.length = website.length <= 50
//1 <= username[i].length <= 10
//0 <= timestamp[i] <= 10^9
//1 <= website[i].length <= 10
//Both username[i] and website[i] contain only lowercase characters.
//It is guaranteed that there is at least one user who 
//visited at least 3 websites. No user visits two websites at the same time.

namespace Solution2019
{
	namespace AnalyzeUserWebsiteVisitPattern
	{
		vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
			int len = username.size();
			unordered_map<string, map<int, string>> m;
			for (int i = 0; i < len; i++) {
				m[username[i]][timestamp[i]] = website[i];
			}
			map<vector<string>, int> counter;
			for (auto& m1 : m) {
				vector<string> allSites;
				for (auto& m2 : m1.second) { 
					allSites.push_back(m2.second); 
				}
				set<vector<string>> seqs;
				for (int k = 0; k < allSites.size(); k++) {
					for (int j = 0; j < k; j++) {
						for (int i = 0; i < j; i++) {
							seqs.insert({ allSites[i], allSites[j], allSites[k] });
						}
					}
				}
				for (auto seq : seqs) { counter[seq]++; }
			}
			auto comp = [](auto& p1, auto& p2) {
				return p1.second < p2.second || p1.second == p2.second && p1.first>p2.first;
			};

			return max_element(counter.begin(), counter.end(), comp)->first;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

