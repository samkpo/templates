#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <iomanip>

#define MAX 100

/*!
 * \fn void showMatrix(T m[MAX][MAX], int f, int c)
 * 
 * Function used to show a matrix \a m of \a f rows and \a c columns
 */
template<class T>
void showMatrix(T m[MAX][MAX], int f, int c){
  std::cout<<"   ";
  for(int i=0; i<f; i++){
    std::cout<<std::setw(4)<<i+1<<" ";
  }std::cout<<std::endl<<"   ";
  for(int i=0; i<f; i++){
    std::cout<<std::setw(4)<<"---"<<" ";
  }std::cout<<std::endl;
  for(int i=0;i<f;i++)
  {
    std::cout<<i+1<<" |";
    for( int j=0;j<f;j++)
    {
      std::cout<<std::setw(4)<<m[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

/*!
 * \fn void generateMatrix(T m[MAX][MAX], int &f, int &c)
 * 
 * Generate a matrix (2-dimentional array) , saving it in \a m,
 * with \a f rows (f comes from filas in spanish) and \a c columns
 */
template<class T>
void generateMatrix(T m[MAX][MAX], int &f, int &c){
  std::cout << "Ingrese numero de filas: ";
  std::cin >> f;
  std::cout << "Ingrese numero de columnas: ";
  std::cin >> c;
  
  for(int i=0; i<f; i++){
    for(int j=0; j<f; j++){
      std::cout<<"Ingrese el elemento ["<<i+1<<std::setw(3)<<j+1<<"]: ";
      std::cin>>m[i][j];}}
      return;
}

#endif