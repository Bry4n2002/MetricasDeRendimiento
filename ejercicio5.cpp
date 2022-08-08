#include <iostream>

void fnx(int x){
    if(x){
         std::cout << x <<std::endl;
    } 
}
int main() {
 
    int i, a = 1234;
    for (i = 0; i < 4; i++){
        fnx(a = a/10);
    }
    

}