#include "stdafx.h"

//Given an integer, write a function to determine if it is a power of three.
//
//Example 1:
//Input: 27
//Output: true
//
//Example 2:
//Input: 0
//Output: false
//
//Example 3:
//Input: 9
//Output: true
//
//Example 4:
//Input: 45
//Output: false
//Follow up:
//Could you do it without using any loop / recursion? 

namespace Solution2019
{
	namespace PowerofThree
	{
		bool isPowerOfThree(int n) {
			double d = log10(n) / log10(3);
			return n > 0 && ceil(d) == floor(d);
		}

		// n = 3^i ---> i = log3(n) ---> i = logb(n)/logb(3);
		//If log10(Bn) / log10(3) returns an int (more precisely, a double but has 0 after
		//decimal point), then n is a power of 3. (original post). But be careful here,
		//you cannot use log (natural log) here, because it will generate round off error
		//for n=243. This is more like a coincidence. I mean when n=243, we have the
		//following results:
		//log(243) = 5.493061443340548    log(3) = 1.0986122886681098
		//   ==> log(243)/log(3) = 4.999999999999999
		//log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
		//   ==> log10(243)/log10(3) = 5.0
		//This happens because log(3) is actually slightly larger than its true value due
		//to round off, which makes the ratio smaller.
		//
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

