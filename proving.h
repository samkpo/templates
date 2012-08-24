#ifndef PROVING_H
#define PROVING_H

#include <ostream>

/*Random class I wrote to use the emplates*/
class Proving
{
public:
  Proving();
  Proving(double a);
  double getValue() const;
  void setValue(double a);
  friend std::ostream& operator<<(std::ostream &o, Proving &p);
  
private:
  double _value = 0;
  
  
};

#endif
