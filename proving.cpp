#include "proving.h"
using namespace std;

Proving::Proving(double a)
{
  _value = a;
}

double Proving::getValue() const
{
  return _value;
}

void Proving::setValue(double a)
{
  _value = a;
}

ostream &operator << (ostream &o, Proving &p)
{
  o << p._value;
  return o;
}
