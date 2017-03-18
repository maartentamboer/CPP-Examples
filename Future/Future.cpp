/*
  Future.cpp
  Fun with std::future

  Maarten Tamboer
  http://dev-tty.nl
*/

#include <iostream>
#include <vector>
#include <future>
#include <chrono>

using namespace std::chrono;

namespace
{
  const int NumberOfThreads = 4;    //Should be multiples of each other
  const int NumberOfVectors = 8;    //Should be multiples of each other
  const int NumberOfItems = 1000000;
}

double CalcAverage(std::vector<double>* v)
{
  double total = 0;
  double items = 0;
  for (auto i : *v)
  {
    total += items;
    items++;
  }

  return total/items;
}

void FillVector(std::vector<double>& v, double start, int count)
{
  v.reserve(count);
  double value = start;
  for(int i = 0; i < count; i++)
  {
    v.push_back(value);
    value++;
  }
}

int main(int argc, char** argv)
{
  std::vector<std::vector<double>> v;
  std::vector<double> results;
  results.reserve(NumberOfVectors);

  for(int i = 0; i < NumberOfVectors; i++)  //Fill with empty
    v.push_back(std::vector<double>());

  for(int i = 0; i<NumberOfVectors; i++)
    FillVector(v.at(i), 0, NumberOfItems);

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  for(int i = 0; i < NumberOfVectors;)
  {
    std::vector<std::future<double>> futures;

    for(int j = 0; j < NumberOfThreads; j++)
    {
      futures.push_back( std::async(CalcAverage, &v.at(i)));
      i++;
    }

    //Now wait for the futures to complete
    for(int j = 0; j < NumberOfThreads; j++)
    {
      results.push_back(futures.at(j).get());
    }
  }
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  std::cout << "It took me " << time_span.count() << " seconds";
  std::cout << std::endl;

  for(int i = 0; i<NumberOfVectors; i++)
    std::cout << "Result of " << i << ": " << results.at(i) << std::endl;

  return 0;
}
