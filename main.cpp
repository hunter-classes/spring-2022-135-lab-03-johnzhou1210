#include <iostream>

#include "reservoir.h"



int main()
{
  std::cout << "get_east_storage(\"01/01/2018\") returns " << get_east_storage("01/01/2018") << "\n";
  std::cout << "get_east_storage(\"07/04/2018\") returns " << get_east_storage("07/04/2018") << "\n";
  std::cout << "get_east_storage(\"12/10/2018\") returns " << get_east_storage("12/10/2018") << "\n";
  return 0;
}
