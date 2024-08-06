//6630300262 teetatpitanupong
#include <iostream>
using namespace std;

int main(){
	char a[4][4] = {{'T','H','I','S'},
					{'W','A','T','S'},
					{'O','A','H','G'},
					{'F','G','D','T'}};
					
	string db[11] = {"IS","THIS","HIS","AT","HI","IT","TWO","OF","THAT","HAT","FAT"};
	string temp = "";

	int count=0;
	
	for(int round = 0;round <4;round++){
		for(int i = 0;i<4;i++){
			for(int j = i;j<4;j++){
				for(int k = i;k<=j;k++){
					temp = temp + a[round][k];
				}
				cout << temp;
				
				for(int i = 0;i < 11;i++){
					if(temp == db[i]){
						cout << " Found "<< ++count;
					}
				}
				cout << endl;
				temp.clear();	
			}
		}
	}
	cout << endl;

	for(int round = 0;round<4;round++){
		for(int i = 0;i<4;i++){
			for(int j = i;j<4;j++){
				for(int k = i;k<=j;k++){
					temp = temp + a[k][round];
				}
				cout << temp;
				
				for(int i = 0;i < 11;i++){
					if(temp == db[i]){
						cout << " Found "<< ++count;
					}
				}
				cout << endl;
				temp.clear();
			}
		}	
	}
	
	for(int i = 3;i>=0;i--){
		for(int j = i;j>=0;j--){
			for(int k = i;k>=j;k--){
				temp = temp + a[k][k];
			}
			cout << temp;
			
			for(int i = 0 ; i <11;i++){
				if(temp == db[i]){
					cout<<" Found "<< ++count;
				}
			}
			cout << endl;
			temp.clear();
			
		}
	}
	
	for(int i = 0;i < 4;i++){
		for(int j = i;j <4;j++){
			for(int k = i;k <= j;k++){
				temp = temp + a[3-k][k];
			}
			cout << temp ;
			for(int i = 0;i<11;i++){
				if(temp == db[i]){
					cout <<" Found "<< ++count;
				}
			}
			
			cout << endl;
			temp.clear();
		}
	}					
	
	cout << endl <<"Total ="<< count;
	return 0;
}

