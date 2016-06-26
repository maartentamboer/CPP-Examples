/*
  LamdaAverage.cpp
  C++ lambda average function example.
  The function has to work with arrays and vectors

  Maarten Tamboer
  http://dev-tty.nl
*/


#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
using std::cout;
using std::endl;

namespace
{
  const uint32_t ArraySize = 100;
}

int main(int argc, char** argv)
{
  auto Seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

  auto RandGen = std::bind(std::uniform_real_distribution<float>(0,10),
                           std::mt19937(Seed));

  //Define a couple of vectors/arrays with randomumbers
  std::vector<float> RandomNumVec1(ArraySize);
  float RandomNumArr1[ArraySize];
  
  std::generate (RandomNumVec1.begin(), RandomNumVec1.end(), RandGen);
  std::generate (RandomNumArr1, RandomNumArr1 + ArraySize, RandGen);

  /*for(uint32_t i=0; i<ArraySize; i++)
  {
    cout << RandomNumVec1[i] << "\t";
    cout << RandomNumArr1[i] << endl;
  }*/

  auto CalcAverage = [](float* Begin, uint32_t Size)
  {
    return std::accumulate(Begin, Begin + Size, 0.0f) / static_cast<float>(Size);
  };

  const auto Average1 = CalcAverage(RandomNumVec1.data(), RandomNumVec1.size());
  const auto Average2 = CalcAverage(RandomNumArr1, ArraySize);

  cout << "Average of RandomNumVec1: " << Average1 << endl;
  cout << "Average of RandomNumArr1: " << Average2 << endl;

  return 0;
}
