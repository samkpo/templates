#include "proving.h"
#include "cdebug.h"
using namespace std;

Proving::Proving(double a)
{
  this->setValue(a);
}

double Proving::getValue() const
{
  return _value;
}

void Proving::setValue(double a)
{
  DEBUG << "Valor: " << a;
  _value = a;
}

ostream &operator << (ostream &o, Proving &p)
{
  o << p._value;
  return o;
}
