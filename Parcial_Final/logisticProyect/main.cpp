/*********************************************************
 * Fecha: 21-09-2022
 * Autor: Bryan Hernandez
 * Materia: HPC-1
 * Tema: Implementacion del algoritmo de Regresion Logpistica
 * Requerimientos:
 *      1.- Crear una clase que permita la manipulacion
 *          de kits de datos(extraccion, normalizacion,
 *          entre otros) con Eigen.
 *      2.- Crear una clase que permita implementar el
 *          modelo o algoritmo de Regresion Logística con
 *          Eigen.
 * ******************************************************/




#include "Extraccion/extraction.h"
#include  <iostream>
#include <list>
#include "ClaseLogistic/regressionlogistic.h"

/* Principal: Captura los argumentos de entrada
 * lugar donde se encuentran el dataset
 * Separador: Delimitador del dataset (;/,/./ / etc.)
 * Header: Si tiene o no cabecera <se elimina si se tiene>
 */

int main(int argc, char *argv[])
{
    /* Se crea un objeto del tipo Extraer
     * para incluir los 3 argumentos que necesita
     * el objeto. */

    Extraction extraerData(argv[1], argv[2], argv[3]);

    std::vector<std::vector<std::string>> dataSET = extraerData.ReadCSV();
        int filas = dataSET.size()+1;
        int columnas = dataSET[0].size();
    // Se crea matriz Egien para extraer los datos de adult_data
    Eigen::MatrixXd MatrizData = extraerData.CSVToEigen(
                    dataSET, filas, columnas);

    // A continuacion se normaliza los datos, no se normaliza la variable target
    Eigen::MatrixXd MatrizNormalizada = extraerData.Normalizador(MatrizData,false);
    //std:: cout<< "Matriz Normalizada \n"<< MatrizNormalizada<<std::endl;



    //std::cout << MatrizData << std::endl;
    std::cout << "Filas : " << filas << std::endl;
    std::cout << "Columnas: " << columnas << std::endl;
    Eigen::MatrixXd promedio =extraerData.Promedio(MatrizData);
    std::cout <<"Promedio" <<std::endl;
    std::cout <<promedio <<std::endl;

    Eigen::MatrixXd sta =extraerData.DesvSTD(MatrizData);
    std::cout <<"Desviacion Estandar" <<std::endl;
    std::cout <<sta <<std::endl;



    /* una vez normalizados los datos, se procede a divir en 4 conjuntos
     * los datos:
     * X_train
     * y_Train
     * X_Test
     * y_Test
     */

     Eigen::MatrixXd X_train, X_Test, y_Train, y_Test;
     std::tuple<Eigen:: MatrixXd, Eigen:: MatrixXd, Eigen:: MatrixXd,Eigen:: MatrixXd> datos_dividos = extraerData.TrainTestSplit(MatrizNormalizada,0.8);
    /* datos_dividos , presenta la tupla comprimida con
     * cuatro matrices . A continuacion se debe descomprimir para
     * las cuatro matrices
     */
     std::tie(X_train,y_Train,X_Test,y_Test)= datos_dividos;

     /* A continuacion se instancia el objeto regresion lineal */
     RegressionLogistic modelo_lr;

     /* Se ajustan los parametros */

     int dimension = X_train.cols();
     Eigen::MatrixXd W = Eigen::VectorXd::Zero(dimension);
     double b = 0;
     double lamda = 0.0;
     bool flag = true;
     double learning_rate = 0.01;
     int iteraciones = 1000;

     Eigen::MatrixXd dw;
     double db;
     std::list<double> lista_costos;

     std::tuple<Eigen::MatrixXd,double,Eigen::MatrixXd,double,std::list<double>> optimo =modelo_lr.Optimization(W, b, X_train, y_Train, iteraciones, learning_rate, lamda, flag);


     /* Se desempaqueta el conjunto de valores optimos */
     std::tie(W, b, dw, db, lista_costos) = optimo;

     /* Se crean las matrices de prediccion, (prueba y entrenamiento) */
     Eigen::MatrixXd y_pred_test = modelo_lr.Prediction(W, b, X_Test);
     Eigen::MatrixXd y_pred_train= modelo_lr.Prediction(W, b, X_train);

     /* A continuacion se calcula la metrica de accuracy para evaluar el rendimiento del modelo */


     auto train_accuracy = 100-((y_pred_train - y_Train ).cwiseAbs().mean() * 100) ;
     auto test_accuracy = 100-((y_pred_test - y_Test ).cwiseAbs().mean() * 100) ;

     std::cout<<"Accuracy de entrenamiento: "<<train_accuracy<<std::endl;
     std::cout<<"Accuracy de prueba: "<<test_accuracy<<std::endl;





     std::cout<<"Filas entrenamiento \n"<< X_train.rows()<<std::endl;
     std::cout<< "Filas Prueba \n" << X_Test.rows()<<std::endl;
     std::cout<<"Filas totales \n"<< MatrizNormalizada.rows()<<std::endl;



    /* Se exporta la función de costo a un fichero*/
      //extraerData.vector_to_file(lista_costos,"ficheroLista.txt");

    //std::list<double> lista_costos;
     /*std::vector<double> lista_costos_vector(lista_costos.begin(),lista_costos.end());

            std::ofstream archivo;
            archivo.open("costos.txt");
            for (int i = 0; i < lista_costos_vector.size(); ++i) {
                archivo << lista_costos_vector[i] << std::endl;
            }
            archivo.close();
*/

     std::vector<double> lista_costos_vector(lista_costos.begin(),lista_costos.end());
     std::ofstream archivo;
     archivo.open("lista_costos.txt");
     for (int i = 0; i < lista_costos_vector.size(); ++i){
         archivo<<lista_costos_vector[i]<<std::endl;
     }
     archivo.close();


    return EXIT_SUCCESS;
}
