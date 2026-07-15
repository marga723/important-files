#include<iostream>
using namespace std;
int main (){
	int num;
	
	cout<<"Enter size:";
	cin>>num;
	int arr[num][num];
	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
		cout<<"Enter matrix:";
		cin>> arr[i][j];
		}
		}
		cout<<"Enter matrix number:"<<endl;
		for(int i=0; i<num;i++){
			for(int j=0;j<num;j++){
				cout<<arr[i][j]<<" ";
				
			}
			cout<<endl;
		}
		cout<<"Sum of rows:"<<endl;
		int row=0;
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				row+=arr[i][j];
				
			}
			cout<<"Row"<<i<<": "<<row<<endl;
			row=0;
		}
		cout<<"Sum of column:"<<endl;
		int col=0;
		for(int i=0;i<num;i++){
		
		for(int j=0;j<num;j++){
			col+=arr[j][i]; 
		}
		cout<<"Column:"<<i<<": "<<col<<endl;
		col=0;
		
}
}
