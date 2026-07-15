#include<iostream>
using namespace std;

int main(){
	int row,col,big,small;
	
	cout<<"Enter the size of row:";
	cin>>row;
	cout<<"Enter the size of column:";
	cin>>col;
	
	int**arr = new int*[row];
	for(int i=0;i<row;i++){
		arr[i]=new int[col];
	}
	
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			cout<<"Enter the value in:["<<a<<"]["<<b<<"]: ";
			cin>>arr[a][b];
			
		}
		cout<<endl;
	}
	cout<<"Matrix:"<<endl;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			cout<<"["<<arr[a][b]<<"]";
		}
		cout<<endl;
	}
	big=0;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			if(arr[a][b]>big){
				big=arr[a][b];
				
			}
		}
		
	}
	cout<<"Biggest value:"<<big;
	small=big;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			if(arr[a][b]<      small){
				small=arr[a][b];
			}
		}
	}
	cout<<endl<<"Smallest value:"<<small;

	

		
}

