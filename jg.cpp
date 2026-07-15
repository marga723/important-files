#include<iostream>
using namespace std;

int main(){
	int num[2][2];
	int sum=0;
	
	for (int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			cout<<"Enter a number:";
			cin>>num[a][b];
		}
	}
	for(int c=0;c<2;c++){
		for(int d=0;d<2;d++){
			cout<<num[c][d]<<" ";
			sum+=[c][d];
		}
		cout<<endl;
	}
	cout<<"Total:"<<sum;
}
