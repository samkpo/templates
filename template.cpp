#include <iostream>
#include <iomanip>
#include <vector>
#include "cdebug.h"
#include "templates.h"
#include "proving.h"

using namespace std;

int main(){
  //saludo :-P
  cout << "Hello\n";
  
  LOG << "Hello 2";
  
  //matriz de enteros
  int m_int[MAX][MAX], f_int, c_int;
  generateMatrix(m_int, f_int, c_int);
  showMatrix(m_int, f_int, c_int);
  
  //matriz de caracteres
  char m_char[MAX][MAX];
  int f_char, c_char;
  generateMatrix(m_char, f_char, c_char);
  showMatrix(m_char, f_char, c_char);
  
  vector<Proving> vec;
  //Proving *p;
  for(int i=0; i<5; i++){
    //p = new Proving(-1 * i);
    vec.push_back(Proving(-1 * i));
    //vec.at(i) << p;
  }
  
  cout << "El vector (0, -1, -2, -3, -4):\n";
  cout << vec;
  
  return 0;
}
