//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a,const int b) {
	if(a<=0||b<=0)
		return -1;
  	int GCD = 1;
	int i = 2;
	int j=a;
	int k=b;
	 if (j < k) {
            while (i <= j) {
                if (j % i == 0 && k % i == 0) {
                    GCD = GCD * i;
                    j = j / i;
                    k = k / i;
                    i = 1;
                }
                i++;
            }
	 }
	 if (k < j) {
            while (i <= k) {
                if (j % i == 0 && k % i == 0) {
                    GCD = GCD * i;
                    j = j / i;
                    k = k / i;
                    i = 1;
                }
                i++;
            }
        }
	if (k == j) 
        GCD = j;
	
	if(GCD<0)
	 return -1;
 return GCD;
}

int leastCommonMultiple (const int a, const int b) {
	if(a<=0||b<=0)
		return -1;
	int LCM= a / greatestCommonDenominator(a,b) * b;
	long int p=a;
	long int f=b;
	long int LCMcheck= p / greatestCommonDenominator(a,b) * f;
	if(LCMcheck>2147483647)
	    return -2;
	if(LCM<0)
		return -1;
    return LCM;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {

  if (argc < 3) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
