#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

/*!
 * \fn void showMatrix(T m[MAX][MAX], int f, int c)
 * 
 * Function used to show a matrix \a m of \a f rows and \a c columns
 */
template<class T>
void showMatrix(T m[MAX][MAX], int f, int c){
  //utilidad para mostrar la matriz de fomra mas "bonita"
  cout<<"   ";
  for(int i=0; i<f; i++){
    cout<<setw(4)<<i+1<<" ";
  }cout<<endl<<"   ";
  for(int i=0; i<f; i++){
    cout<<setw(4)<<"---"<<" ";
  }cout<<endl;
  for(int i=0;i<f;i++)
  {
    cout<<i+1<<" |";
    for( int j=0;j<f;j++)
    {
      cout<<setw(4)<<m[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

template<class T>
void generateMatrix(T m[MAX][MAX], int &f, int &c){
  cout << "Ingrese numero de filas: ";
  cin >> f;
  cout << "Ingrese numero de columnas: ";
  cin >> c;
  
  for(int i=0; i<f; i++){
    for(int j=0; j<f; j++){
      cout<<"Ingrese el elemento ["<<i+1<<setw(3)<<j+1<<"]: ";
      cin>>m[i][j];}}
      return;
}

int main(){
  //saludo :-P
  cout << "Hello\n";
  
  //matriz de enteros
  int m_int[MAX][MAX], f_int, c_int;
  generateMatrix(m_int, f_int, c_int);
  showMatrix(m_int, f_int, c_int);
  
  //matriz de caracteres
  char m_char[MAX][MAX];
  int f_char, c_char;
  generateMatrix(m_char, f_char, c_char);
  showMatrix(m_char, f_char, c_char);
  return 0;
}
