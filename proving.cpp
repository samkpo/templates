#include "proving.h"

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


