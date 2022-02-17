#include <iostream>
#include <fstream>
#include <vector>

#include "reservoir.h"

std::string determineEarlierDate(std::string date1, std::string date2)
{
  int month1 = std::stoi(date1.substr(0,2));
  int month2 = std::stoi(date2.substr(0,2));
  if (month1 > month2)
  {
    return date2;
  } else if (month1 != month2) {
    return date1;
  }
  // now take care of the month's date
  int monthDay1 = std::stoi(date1.substr(3,2));
  int monthDay2 = std::stoi(date2.substr(3,2));
  if (monthDay1 > monthDay2)
  {
    return date2;
  }
  return date1;
}

void reverse_oreder(std::string date1, std::string date2)
{
  // first determine which date is earlier
  std::string earlierDate, laterDate;
  earlierDate = determineEarlierDate(date1, date2);
  if (earlierDate == date1)
  {
    laterDate = date2;
  } else {
    laterDate = date1;
  }
  // std::cout << "earlier date is: " << earlierDate << " and later date is " << laterDate << "\n";

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
  std::vector<std::string> dates = {};
  std::string currLn;
  int appendStatus = 0; // 0 is not started yet, 1 is in process, 2 is done
  while (std::getline(file, currLn)) // while you can still read
  {
    // split string line into an array
    // make sure also to add the west basin elevation to the day
      std::vector<std::string> arr = tabSplit(currLn);
      if (arr[0] == earlierDate)
      {
        // std::cout << "arr[4] is " << arr[4] << std::endl;
        appendStatus = 1;
        dates.push_back(arr[0] + "\t" + arr[4]);
      }
      else if (arr[0] == laterDate)
      {
        dates.push_back(arr[0] + "\t" + arr[4]);
        appendStatus = 2;
      }
      else if (appendStatus == 1)
      {
        dates.push_back(arr[0] + "\t" + arr[4]);
      }
      //std::cout << arr.size() << "\n";
      //std::cout << "output is " << arr[0] << "\n";
  }

  // print out array but backwards
  for (int i = dates.size(); i >= 0; i--)
  {
    std::cout << dates[i] << std::endl;
  }
  std::cout << "\n";

  file.close();
}
