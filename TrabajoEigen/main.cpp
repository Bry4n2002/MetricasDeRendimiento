/**
 * @author Bryan Hernandez
 * @date   21 Agosto 2022
 * @title Ejercicios Eigen.
 *
 */


#include<vector>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <math.h>
using namespace std;


int main()
{
    // Se crean las matrices 2x2
    Eigen:: Matrix2d a;
    Eigen:: Matrix2d b;

    // A. X=3A-4B

    /*
     * Se construye la matrices con los diferentes valores
     */

    a<< 4,-2,
        1,-7;
    b<< -1,2,
        6,-5;

    /* Se imprime le resultado de la operación
     * En este ejercio de aplica las operaciones de multiplcación,
     * resta entre matrices
     */
    std::cout << " Ejercico A \n"<< std::endl;
    std::cout  << (3 * a)-(4*b)<< std::endl;


    // B. 2X+4A=3BA
    /*
     * Se sigue usando las matrices ya creadas inicialmente con
     * valores diferentes.
     */
    a<<0,-1,
            2,1;
    b<<1,2,
            3,4;

    /* Se imprime el resultado de la operación
     * En este ejercio de aplica las operaciones de multiplcación,
     * división y resta entre matrices
     *
     */

    std::cout << " Ejercico B \n"<< std::endl;
    std::cout  << ((3*b*a)-(4*a))/(2)<< std::endl;


    // C. AXBt=C
    /*
     * Se sigue usando las matrices ya creadas inicialmente con
     * valores diferentes y se crea una nueva matriz.
     */

    Eigen:: Matrix2d c;
   // Se construyen las matrices con los nuevos valores.
    a<<-3,-2,
            3,3;
    b<<5,3,
            9,4;
    c<<1,1,
            0,0;
    // Se imprime el resultado de la operación
    std::cout << " Ejercico C \n"<< std::endl;
    std::cout  <<" "<< std::endl;


    // D. XA=B
    // Se construyen las matrices con los nuevos valores.
    a<<2,1,
            -4,-3;
    b<<2,2,
            6,4;
   /* En este ejercio de aplica las operaciones de multiplcación
    * entre matrices con diferencia de que una de las matrices se le
    * aplica la funcion .inverse() la cual calcula la inversa de la matriz.
    */

    // Se imprime el resultado
    std::cout << " Ejercico D \n"<< std::endl;
    std::cout <<b*a.inverse()<< std::endl;


    // E. X=2(AB*C)
    /*
     * Se crean nuevas matrices con diferentes dimensiones
     */
    Eigen:: MatrixXd aa(2,3);
    Eigen:: MatrixXd bb(3,2);
    Eigen:: Matrix2d cc;

    /* Se cargan la matrices con valores */
    aa<<3,0,-1,
            0,2,1;
    bb<<1,2,
            1,0,
            0,6;
    cc<<-2,0,
            -2,-5;

    /* Se imprime el resultado de la operación
     * En este ejercio de aplica las operaciones de suma,
     * y multiplicacion por un escalar
     *
     */

    std::cout << " Ejercico E \n"<< std::endl;
    std::cout  << (2*((aa*bb)+cc))<< std::endl;

    // F. X=A+3B
    /*
     * Se crean nuevas matrices con dimensiones 3x3
     */

     Eigen:: Matrix3d af;
     Eigen:: Matrix3d bf;
    /* Se cargan la matrices con valores */
     af<<1,5,-1,
             -1,2,2,
             0,-3,3;
     bf<<-1,-4,3,
             1,-2,-2,
             -3,3,-5;

     /* Se imprime el resultado de la operación
      * En este ejercio de aplica las operaciones de suma,
      * y multiplicacion por un escalar.
      *
      */
     std::cout << " Ejercico F \n"<< std::endl;
     std::cout  <<af+(3*bf)<< std::endl;


      // H. AX=B
      /*
       * Se usa las misma matrices 3x3 pero con diferentes valores
       */
     af<<1,1,1,
             6,5,4,
             13,10,8;
     bf<<0,1,2,
             1,0,2,
             1,2,0;

     /* En este ejercio de aplica las operaciones de multiplcación
      * entre matrices con diferencia de que una de las matrices se le
      * aplica la funcion .inverse() la cual calcula  la matriz indentidad entre dos matrices .
      */

     // Se impreme resultado de la operación
     std::cout << " Ejercico H \n"<< std::endl;
     std::cout  <<af.inverse()*bf<< std::endl;




     // I. X=AtA-2A
     /*
      * Uso de la mismas matrices 2x2 ya creadas con respectivos valores
      */
     a<<3,-1,
             0,2;
     /*
      *En este ejercio de aplica las operaciones de multiplcación,resta
      * entre matrices con diferencia de que una de las matrices se le
      * aplica la funcion .tranpose() la cual hace el cambio de columnas por filas y
      * filas por columnas.
      */
     //Se imprime el resultado de la operación
     std::cout << " Ejercico I \n"<< std::endl;
     std::cout  <<a.transpose()*a-2*a<< std::endl;


     // J. X=A³
     /*
      * Uso de la mismas matrices 2x2 ya creadas con respectivos valores
      */
     a<<4,2,
             -1,0;
     /*
      * En ejercicio se simula la potencia de una matriz.
      */

     //Se imprime el resultado de la operación
     std::cout << " Ejercico J \n"<< std::endl;
     std::cout  <<a*a*a<< std::endl;

     // I. X=AA^T-2AB

     /*
      * Se usa matrices de puntos anteriores
      */
     aa<<1,0,-2,
             2,-1,3;
     bb<<2,-3,
             -2,0,
             -1,-2;
     a<<3,-1,
             0,2;
     /*
      *En este ejercio de aplica las operaciones de multiplcación,resta
      * entre matrices con diferencia de que una de las matrices se le
      * aplica la funcion .tranpose() la cual hace el cambio de columnas por filas y
      * filas por columnas.
      */

     //Se imprime el resultado de la operación
     std::cout << " Ejercico L \n"<< std::endl;
     std::cout  <<aa*aa.transpose()-2*aa*bb<< std::endl;

     // M. X=ABC
     /*
      * Se crean nuevas matrices con diferentes dimesiones a las anteriores
      */
     Eigen:: MatrixXd a_m(1,3);
     Eigen:: MatrixXd c_m(2,1);
    /*
     * Se contruyen con valores nuevos.
     */
     a_m<<4,8,12;
     bb<<3,2,
             0,1,
             -1,0;
     c_m<<3,
             -1;
     /*
      *En este ejercio de aplica las operaciones de multiplcación entre matrices.
      */

     //Se imprime el resultado de la operación
     std::cout << " Ejercico M \n"<< std::endl;
     std::cout  << a_m*bb*c_m << std::endl;

     // N. AtX=B

     Eigen:: Matrix3d a_O;
     Eigen:: Matrix3d b_O;
     a_O<<2,5,7,
             6,3,4,
             5,-2,-3;
     b_O<<-1,1,0,
             0,1,1,
             1,0,-1;
     std::cout << " Ejercico O \n"<< std::endl;
     std::cout  << a_O.inverse()*b_O << std::endl;



}
