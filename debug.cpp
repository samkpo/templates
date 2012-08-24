#include "cdebug.h"
#include <ctime>
#include <iomanip>

void ShowInfo::show_time(){
  time_t rawtime;
  struct tm *ti;
  
  time ( &rawtime );
  ti = localtime ( &rawtime );

  std::cout << std::setw(2) << ti->tm_hour << ":"
            << std::setw(2) << ti->tm_min << ":"
            << std::setw(2) << ti->tm_sec;
}


