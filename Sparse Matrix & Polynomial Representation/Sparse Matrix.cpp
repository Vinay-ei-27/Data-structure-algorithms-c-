#include<bits/stdc++.h>
using namespace std;

class Element{
	public:
		int i;
		int j;
		int x;
};

class Sparse{
	private:
		int m;
		int n;
		int num;
		Element *ele;
		
	public:
		Sparse(int a, int b, int c){
			m = a;
			n = b;
			num = c;
			ele = new Element[num];
		}
		~Sparse(){
			delete [] ele;
		}
		Sparse operator+(Sparse &s);
		friend istream & operator>>(istream &is, Sparse &s);
		friend ostream & operator<<(ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s){
	int i, j, k;
	if(m != s.m || n != s.n){
		return Sparse(0,0,0);
	}
	Sparse *sum = new Sparse(m, n, num + s.num);
	
	i=j=k=0;
	while(i < num && j < s.num){
		if(ele[i].i < s.ele[j].i){
			sum->ele[k++] = ele[i++];
		}
		else if(ele[i].i > s.ele[j].i){
			sum->ele[k++] = s.ele[j++];
		}
		else{
			if(ele[i].j < s.ele[j].j){
				sum->ele[k++] = ele[i++];
			}
			else if(ele[i].j > s.ele[j].j){
				sum->ele[k++] = s.ele[j++];
			}
			else{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}
	for( ; i < num; i++){
		sum->ele[k++] = ele[i];
	}
	for( ; j < s.num; j++){
		sum->ele[k++] = s.ele[j];
	}
	sum->num = k;
	return *sum;
}

istream & operator>>(istream &is, Sparse &s){
	cout<<"Enter Non-Zero Elements: ";
	for(int i = 0; i < s.num; i++){
		cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
	}
	return is;
}

ostream & operator<<(ostream &os, Sparse &s){
	int k = 0;
	for(int i = 0; i < s.m; i++){
		for(int j = 0; j < s.n; j++){
			if(i == s.ele[k].i && j == s.ele[k].j){
				cout<<s.ele[k++].x<<" ";
			} else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	return os;
}

int main()
{
	Sparse S1(5, 5, 5);
	Sparse S2(5, 5, 5);
	
	cin>>S1;
	cin>>S2;
	
	Sparse sum = S1 + S2;
	
	cout<<"First Matrix: "<<endl<<S1;
	cout<<"Second Matrix: "<<endl<<S2;
	cout<<"Sum Matrix: "<<endl<<sum;
	return 0;
}
