#include <iostream>


int main(){
    
    // Declaración de variables
    int dia, mes, anio, suma = 0;
    
    // Entrada de datos
    std::cout << "Introduce un valor para dia: ";
    std::cin >> dia;
    std::cout << "Introduce un valor para mes: ";
    std::cin >> mes;
    std::cout << "Introduce un valor para anio: ";
    std::cin >> anio;
    
    //condicional que no acepte valores negativos para a y b
    if (dia < 0 || mes < 0 || anio < 0){
        std::cout << "No se aceptan valores negativos" << std::endl;
    }else{

        //tarot
        suma = dia + mes + anio;

        //ciclo que suma los digitos de la suma
        while (suma > 9){
            suma = suma/10 + suma%10;
        }
        

       
        //imprime los resultados 
        std::cout<<"\n\nRESULTADOS"<<std::endl;
        std::cout << "\nEl numero de Tarot de la fecha de nacimiento es: " << suma % 10 << "\n\n" << std::endl;
    }
    
    
    
    
    return 0;
}