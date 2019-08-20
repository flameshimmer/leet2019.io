#include "stdafx.h"

//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//Input : "abcabcbb"
//Output : 3
//Explanation : The answer is "abc", with the length of 3.
//
//Example 2 :
//Input : "bbbbb"
//Output : 1
//Explanation : The answer is "b", with the length of 1.
//
//Example 3 :
//Input : "pwwkew"
//Output : 3
//Explanation : The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

namespace Solution2019
{
	namespace LongestSubstringWithoutRepeatingCharacters
	{
		int LongestSubstringWithoutRepeatingCharacters(string s)
		{
			int len = s.size();
			if (len < 2) { return len; }

			int map[256]; // Using int array instead of hashmap. This is very efficient!. 
			memset(map, -1, sizeof(map)); // using memset to set the init the array!
			int start = 0;
			int end = 0;
			int longest = 0;
			while (end < len) {
				char c = s[end];
				if (map[c] != -1) {
					longest = max(longest, end - start);
					start = max(start, map[c] + 1); // Notice this line! This is equivalent to clearing the hashmap. Very interesting and very fast. 
				}
				map[c] = end;
				end++;				
			}
			longest = max(longest, end - start); // Don't forget to do this!
			return longest;
		}


		int LongestSubstringWithoutRepeatingCharactersNotVeryEffecitent(string input)
		{
			int len = input.size();
			if (len < 2) { return len; }

			unordered_map<char, int> map;
			int start = 0;
			int end = 0;
			int result = 0;

			while (end < len)
			{
				if (map.find(input[end]) != map.end())
				{
					result = max(result, end - start);
					while (start < map[input[end]])
					{
						map.erase(input[start]);
						start++;
					}
					start = map[input[end]] + 1;
				}
				map[input[end]] = end;
				end++;
			}
			result = max(result, end - start);
			return result;
		}

		void Main() {			
			print(LongestSubstringWithoutRepeatingCharacters("abba"));
			print(LongestSubstringWithoutRepeatingCharacters("abcabcbb"));
			print(LongestSubstringWithoutRepeatingCharacters("bbbbbbbb"));
			print(LongestSubstringWithoutRepeatingCharacters("pwwkew"));
			print(LongestSubstringWithoutRepeatingCharacters("au"));
			
		}
	}
}

