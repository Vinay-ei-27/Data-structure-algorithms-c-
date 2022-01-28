#include<bits/stdc++.h>
using namespace std;

int fact(int n){
	if(n == 0){
		return 1;
	}
	return n * fact(n - 1);
}

int nCr(int n, int r){
	int num, den;
	
	num = fact(n);
	den = fact(r) * fact(n - r);
	return num/den;
}

// Recursive Function :-

int NCR(int n, int r){
	if(r == 0 || n == r){
		return 1;
	}
	return NCR(n-1, r-1) + NCR(n-1, r);
}

int main()
{
	cout<<NCR(7, 3);
	return 0;
}
