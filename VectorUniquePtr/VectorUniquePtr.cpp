/*
  VectorUniquePtr.cpp
  Make a vector of unique pointers to a class

  Maarten Tamboer
  http://dev-tty.nl
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cout;
using std::endl;


class CPassenger
{
public:
  CPassenger(const char* N, unsigned int A)
  : Number(A)
  { Name.assign(N); };
  std::string Name;
  unsigned int Number;
};


int main(int argc, char** argv)
{
  std::vector<std::unique_ptr<CPassenger>> Passengers;

  for(int i = 0; i<10; i++)
  {
    //Passengers.push_back(std::unique_ptr<CPassenger>(new CPassenger("Maarten", i)));  //C++11
    Passengers.push_back(std::make_unique<CPassenger>("Maarten", i));     //C++14
  }

  cout << "The vector now contains " << Passengers.size() << " Passengers" << endl;

  for(auto it = Passengers.begin(); it!=Passengers.end(); ++it)
  {
    cout << "Number: " << (*it)->Number << " Name: " << (*it)->Number << endl;
  }

  cout << "Cleaning up" << endl;

  Passengers.clear();

  return 0;
}
