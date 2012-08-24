#include <iostream>
#include <iomanip>
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
  return 0;
}
