// Leet2019.cpp : Defines the entry point for the console application.
//

// Leet2015.cpp : Defines the entry point for the console application.
//reverse
#include "stdafx.h"
#include "Solution2019.h"


using namespace std;
typedef std::numeric_limits< double > dbl;

int _tmain(int argc, _TCHAR* argv[])
{
	// Runtime begin marker start
	clock_t begin = clock();

	//Solution2019::Test::Main(); // Medium
	
	// 8/15/2019
	Solution2019::TwoSum::Main();
	


	// Runtime end marker
	clock_t end = clock();
	double elapsed_time_in_millisecond = double(end - begin) / double(CLOCKS_PER_SEC / 1000.0);

	// End program routine
	cout.precision(dbl::digits10);
	cout << "\n\nYour program total runtime is: " << elapsed_time_in_millisecond << "ms";
	cout << "\n\nPress enter key to exit ...\n\n";
	cin.get();
	return 0;
}

