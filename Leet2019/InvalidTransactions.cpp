#include "stdafx.h"
//A transaction is possibly invalid if:
//the amount exceeds $1000, or;
//if it occurs within (and including) 60 minutes of 
//another transaction with the same name in a different city.
//Each transaction string transactions[i] consists of 
//comma separated values representing the name, time 
//(in minutes), amount, and city of the transaction.
//
//Given a list of transactions, return a list of transactions
//that are possibly invalid.  You may return the answer in any order.
//
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because 
//the second transaction occurs within a difference of 60 
//minutes, have the same name and is in a different city. 
//Similarly the second one is invalid too.
//
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//transactions.length <= 1000
//Each transactions[i] takes the form "{name},{time},{amount},{city}"
//Each {name} and {city} consist of lowercase English 
//letters, and have lengths between 1 and 10.
//Each {time} consist of digits, and represent an integer 
//between 0 and 1000.
//Each {amount} consist of digits, and represent an integer
//between 0 and 2000. 

namespace Solution2019
{
	namespace InvalidTransactions
	{
		vector<string> invalidTransactions(vector<string>& transactions) {
			unordered_set<string> result;
			unordered_map<string, vector<vector<string>>>m;
			for (auto& t : transactions) {
				istringstream ss(t);
				vector<string> s(4, "");
				int i = 0;
				while (getline(ss, s[i++], ','));
				if (stoi(s[2]) > 1000) { result.insert(t); }
				for (vector<string> j : m[s[0]]) {
					if (j[3] != s[3] && abs(stoi(j[1]) - stoi(s[1])) <= 60) {
						result.insert(j[0] + "," + j[1] + "," + j[2] + "," + j[3]);
						result.insert(t);
					}
				}
				m[s[0]].push_back({ s[0], s[1], s[2], s[3] });
			}
			vector<string> finalResult;
			for (auto& str : result) { finalResult.push_back(str); }
			return finalResult;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

