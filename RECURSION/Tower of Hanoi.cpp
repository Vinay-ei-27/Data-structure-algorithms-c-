#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int A, int B, int C){
	if(n > 0){
		hanoi(n-1, A, C, B);
		cout<<"("<<A<< " to "<<C<<")"<<endl;
		hanoi(n-1, B, A, C);
	}
}

int main()
{
	hanoi(3, 1, 2, 3);
	return 0;
}
