#include <iostream>
using namespace std;

int main(){
	int cantFilas, contador1 = 0, contador2 = 1, numeros = 1, espacios;
	
	cout<<"Digite el numero de filas"<<endl;
	cin>>cantFilas;
	cout<<endl;
	espacios =cantFilas;
	for(int i=0; i<cantFilas; i++){
		for(int j=espacios; j>0; j--){
			cout<<"   ";
		}
		while(contador1 != contador2){
			
			cout<<"  ";
			if(contador1>=1){
				if(contador1 >= (i+1)){
					numeros--;
					if(numeros>=20){
						cout<<(numeros-20);
					}else if(numeros>=10){
						cout<<(numeros-10);
					}else{
						cout<<numeros;
					}
					
				}else{
					numeros++;
					if(numeros>=20){
						cout<<(numeros-20);
					}else if(numeros>=10){
						cout<<(numeros-10);
					}else{
						cout<<numeros;
					}
				}
			}else{
				if(numeros>=10){
					cout<<(numeros-10);
				}else{
					cout<<numeros;
				}
			}
		
			contador1++;
		}
		
		cout<<endl;
		numeros++;
		contador2 += 2;
		contador1 = 0;
		espacios--;
	}
}