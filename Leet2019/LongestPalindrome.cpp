#include "stdafx.h"
//
//Given a string which consists of lowercase or uppercase letters, 
//find the length of the longest palindromes that can be built with those letters.
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//Assume the length of given string will not exceed 1, 010.
//Example :
//
//Input :
//"abccccdd"
//
//Output :
//7
//Explanation :
//One longest palindrome that can be built is "dccaccd", whose length is 7.
//
namespace Solution2019
{
	namespace LongestPalindrome
	{
		int LongestPalindrome(string s) {
			int len = s.size();
			if (len < 2) return len;

			int map[256];
			memset(map, 0, sizeof(map));
			for (char c : s) {
				map[c]++;
			}
			int result = 0;
			for (int i : map) {
				result += i / 2 * 2;
				if (i % 2 == 1 && result % 2 == 0) { result++; }
			}
			
			return result;		
		}


		void Main() {
			print(LongestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"));
		}
	}
}

