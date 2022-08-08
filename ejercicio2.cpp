#include <iostream>
int main()
{
    int x = 1, y = 1;
    if(x==1){
        if(y==0){
            x=10;
        }
    }else{
        x=-1;
    }
    std::cout << x <<std::endl;

}