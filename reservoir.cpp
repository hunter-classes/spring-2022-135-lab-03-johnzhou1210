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
      // std::cout << "adding " << str.substr(lastCutPoint, i - lastCutPoint) << ", with cut point at index " << lastCutPoint << " with length " << i << std::endl;
      result.push_back(str.substr(lastCutPoint, i - lastCutPoint));
      // std::cout << result.size() << "\n";
      lastCutPoint = i + 1;
    } else {
      // std::cout << "compare method returned " << currString.compare("\t") << "\n";
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
        file.close();
        return std::stod(arr[1]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }
  file.close();
  return -1;
}

double get_west_storage(std::string date)
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
        file.close();
        return std::stod(arr[3]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }
  file.close();
  return -1;
}

double get_west_elevation(std::string date)
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
        file.close();
        return std::stod(arr[4]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }
  file.close();
  return -1;
}

double get_east_elevation(std::string date)
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
        file.close();
        return std::stod(arr[2]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }
  file.close();
  return -1;
}

double get_min_east()
{
  double minStorage = (double)LONG_MAX;
  //std::cout << "1: " << minStorage << std::endl;
  // returns minimum East Basin storage for 2018 (all data is in 2018; no need to filter)
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
    double currStorage =  std::stod(arr[1]);
    //std::cout << "1: " << currStorage << std::endl;
    if (currStorage < minStorage)
      {
        minStorage = currStorage;
      }
    //std::cout << arr.size() << "\n";
    //std::cout << "output is " << arr[0] << "\n";

  }
  file.close();
  return minStorage;
}

double get_max_east()
{
  double maxStorage = (double)LONG_MIN;
  //std::cout << "1: " << minStorage << std::endl;
  // returns minimum East Basin storage for 2018 (all data is in 2018; no need to filter)
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
    double currStorage =  std::stod(arr[1]);
    //std::cout << "1: " << currStorage << std::endl;
    if (currStorage > maxStorage)
      {
        maxStorage = currStorage;
      }
    //std::cout << arr.size() << "\n";
    //std::cout << "output is " << arr[0] << "\n";

  }
  file.close();
  return maxStorage;
}

std::string compare_basins(std::string date)
{
  if (get_east_elevation(date) == get_west_elevation(date))
  {
    return "Equal";
  }
  else if (get_east_elevation(date) > get_west_elevation(date))
  {
    return "East";
  }
  return "West";
}
