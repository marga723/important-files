#include<iostream>
using namespace std;
int main(){
	int n;



cout<<"Enter Number:"<<endl;
cin>>n;

int arr[n];
cout<<"Enter"<<n<<"Elements:"<<endl;
for(int a=0;a<n;a++){
	cin>>*(arr + a);
}
int*fptr =arr;
int*lptr =arr;
int*hptr =arr;
int*mptr =arr +(n/2);
int*laptr =arr +(n-1);

for(int a=1;a<n;a++){
	if(*(arr +a)< *lptr){
		lptr =arr+a;
	}
	if(*(arr +a)> *hptr  ){
		hptr =arr+a;
	}
}

cout<<"Middle Number is:"<<*mptr<<endl;
cout<<"Lowest Number is:"<<*lptr<<endl;
cout<<"Highest Number is:"<<*hptr<<endl;
cout<<"First Number is:"<<*fptr<<endl;
cout<<"Last Number is:"<<*laptr<<endl;


}

