#include <iostream>
#include <vector>

#include "reservoir.h"
#include "reverseorder.h"



int main()
{
  std::cout << "========================= TASK A =========================\n";
  std::cout << "get_east_storage(\"01/01/2018\") returns " << get_east_storage("01/01/2018") << "\n";
  std::cout << "get_east_storage(\"07/04/2018\") returns " << get_east_storage("07/04/2018") << "\n";
  std::cout << "get_east_storage(\"12/10/2018\") returns " << get_east_storage("12/10/2018") << "\n";
  std::cout << "========================= TASK B =========================\n";
  std::cout << "get_min_east() returns " << get_min_east() << "\n";
  std::cout << "get_max_east() returns " << get_max_east() << "\n";
  std::cout << "========================= TASK C =========================\n";
  std::cout << "compare_basins(\"04/01/2018\") returns " << compare_basins("04/01/2018") << "\n";
  std::cout << "compare_basins(\"11/09/2018\") returns " << compare_basins("11/09/2018") << "\n";
  std::cout << "compare_basins(\"06/25/2018\") returns " << compare_basins("06/25/2018") << "\n";
  std::cout << "========================= TASK D =========================\n";
  std::cout << "reverse_oreder(\"03/29/2018, 04/04/2018\") prints:"; reverse_oreder("03/29/2018", "04/04/2018");
  return 0;
}
