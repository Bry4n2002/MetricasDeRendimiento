#include <iostream>


int main(){
    
    int a, b, suma = 0;
    
    std::cout << "Introduce un valor para a: ";
    std::cin >> a;
    std::cout << "Introduce un valor para b: ";
    std::cin >> b;
    if (a < 0 || b < 0){
        std::cout << "Ingrese valores que sean enteros" <<std::endl;
    }else if (a > b){
            int aux = a;
            a = b;
            b = aux;
        }
    

    for (int i = a; i <= b; i++){
        if (i % 5 == 0){
            suma += i;
        }
    }
    
    std::cout << "La suma de los múltiplos de 5 comprendidos entre " << a << " y " << b << " el resultado de la ejecucion es: " << suma << std::endl;
    
    return 0;
}