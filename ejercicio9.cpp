#include <iostream>
using namespace std;

int main(){
	int finRango;
	double resultado = 0.0, x, y;
	cout<<"Digite el fin del rango de la sumatoria"<<endl;
	cin>>finRango;
	
	cout<<"Digite el valor de X"<<endl;
	cin>>x;
	cout<<"Digite el valor de y"<<endl;
	cin>>y;
	
	for(int i = 0; i < finRango; i++){
		resultado += 1/(x+(i*y));	
	}
	
	cout<<"\nEL RESULTADO ES: "<<resultado<<endl;
}