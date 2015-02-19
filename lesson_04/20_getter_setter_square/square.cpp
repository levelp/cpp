#include "square.h"

// Реализация метода в отдельном C++ файле
//-->
void Square::setArea(double value) {
#ifdef SIDE
  side = sqrt(value);
#else
  area = value;
#endif
}
//<--
