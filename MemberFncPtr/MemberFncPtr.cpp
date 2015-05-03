/*
  MemberFncPtr.cpp
  C++ Member function pointer example

  Maarten Tamboer
  http://dev-tty.nl
*/

#include <iostream>
using std::cout;
using std::endl;

class CClassWithFncPtr
{
public:
  CClassWithFncPtr()
  {
    mpFunc1Ptr = &CClassWithFncPtr::Func1_1;
    mpFunc2Ptr = &CClassWithFncPtr::Func2_1;
  }
  bool Func1_1(void){ std::cout << __FUNCTION__ << endl; return false; };
  bool Func1_2(void){ std::cout << __FUNCTION__ << endl; return true; };
  int  Func2_1(int Par1, int Par2){ std::cout << __FUNCTION__ << endl; return Par1 + Par2; };
  int  Func2_2(int Par1, int Par2){ std::cout << __FUNCTION__ << endl; return Par1 - Par2; };

  void SelectFunc1(int Select)
  {
    if (Select == 1)
      mpFunc1Ptr = &CClassWithFncPtr::Func1_1;
    else
      mpFunc1Ptr = &CClassWithFncPtr::Func1_2;
  };

  void SelectFunc2(int Select)
  {
    if (Select == 1)
      mpFunc2Ptr = &CClassWithFncPtr::Func2_1;
    else
      mpFunc2Ptr = &CClassWithFncPtr::Func2_2;
  }

  bool ExecuteFunc1(void)
  {
    return (this->*mpFunc1Ptr)();
  }

  int ExecuteFunc2(int Par1, int Par2)
  {
    return (this->*mpFunc2Ptr)(Par1, Par2);
  }

private:
  bool (CClassWithFncPtr::*mpFunc1Ptr)(void);
  int  (CClassWithFncPtr::*mpFunc2Ptr)(int, int);
};


int main(int argc, char** argv)
{
  CClassWithFncPtr Example;

  std::cout << "**** Using Member function pointer within a class ****" << endl;

  Example.SelectFunc1(1);
  const char *Ret = Example.ExecuteFunc1() ? "True" : "False";
  std::cout << "Func1 returned: " << Ret << endl;

  Example.SelectFunc1(2);
  Ret = Example.ExecuteFunc1() ? "True" : "False";
  std::cout << "Func1 returned: " << Ret << endl;


  std::cout << endl << "**** Using Member function pointers outside a class ****" << endl;

  int  (CClassWithFncPtr::*Func2Ptr)(int, int);
  Func2Ptr = &CClassWithFncPtr::Func2_1;
  int Retval = (Example.*Func2Ptr)(2, 3);
  std::cout << "Func2 returned: " << Retval << endl;


  Func2Ptr = &CClassWithFncPtr::Func2_2;
  Retval = (Example.*Func2Ptr)(2, 3);
  std::cout << "Func2 returned: " << Retval << endl;

  return 0;
}
