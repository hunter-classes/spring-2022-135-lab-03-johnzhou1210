#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

std::vector<std::string> tabSplit(std::string str)
{
  int lastCutPoint = 0;
  std::vector<std::string> result = {};
  for (int i = 0; i < str.length()-1; i++)
  {
    std::string currString = str.substr(i,1);
    // std::cout << currString << std::endl;
    if (currString == "\t")
    {
      result.push_back(str.substr(lastCutPoint, i));
      //std::cout << result.size() << "\n";
      lastCutPoint = i + 1;
    } else {
      //std::cout << "compare method returned " << currString.compare("\t") << "\n";
    }
  }
  return result;
}

double get_east_storage(std::string date)
{
  // returns East Basin storage for given date
  std::ifstream file;
  file.open("Current_Reservoir_Levels.tsv");
  if (file.fail())
  {
    std::cerr << "File cannot be opened for reading.\n";
    exit(1);
  }
  // ignore first line by reading it first (first line is header)
  std::string header;
  std::getline(file, header);
  // now read line by line
  std::string currLn;

  while (std::getline(file, currLn)) // while you can still read
  {
    // split string line into an array
      std::vector<std::string> arr = tabSplit(currLn);
      if (arr[0] == date)
      {
        return std::stod(arr[1]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }
  file.close();
  return -1;
}
