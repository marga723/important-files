#include<iostream>
#include<fstream>
using namespace std;

int main(){
	

	int q;
	float total;
	int ally;
	float payment;
	float change;
	

	
	cout<<"------------MENU-----------"<<endl;
	cout<<"1.Chicken Wings----------------100"<<endl;
	cout<<"2.CONDOM-----------------------200"<<endl;
	cout<<"3.ROBUST-----------------------300"<<endl;
	
	cout<<"Choose your order:";
	cin>>ally;
	
	
	switch (ally){
		
		case 1: cout<<"Quantity:";
					cin>>q;
			total = 100 * q;
		break;
		case 2: cout<<"Quantity:";
					cin>>q;
			total = 200 * q;
		break;
		case 3: cout<<"Quantity:";
					cin>>q;
			total = 300 * q;
		break;
		
	
		
		
	}
	
	
		cout<<"Total:"<<total<<endl;
		
		cout<<"BAYAD:";
		cin>>payment;
		
		change = payment - total;
		
		cout<<"TUKLELE:"<<change<<endl;
		
		fstream raicen;
		raicen.open("KAYO NA BAHALA",ios::out);
		if(raicen.is_open()){

			raicen<<"----------MENU-----------"<<endl;
			raicen<<"1.Chicken Wings----------------100"<<endl;
			raicen<<"2.CONDOM---------------200"<<endl;
			raicen<<"3.ROBUST--------------300"<<endl;
			
			raicen<<"---------------------------"<<endl; 
			
			raicen<<"ORDER:"<<ally<<endl;
			raicen<<"TOTAL:"<<total<<endl;
			raicen<<"BAYAD:"<<payment<<endl;
			raicen<<"TUKLELE:"<<change<<endl;
			
			
			
			
			
			
			
		}
		
		
		
		
		
	return 0;
	
}