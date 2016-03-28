/*
  GenericFncPtr.cpp
  C++ Generic Member function pointer example

  Maarten Tamboer
  http://dev-tty.nl
*/

#include <iostream>
using std::cout;
using std::endl;

class IFncPtr
{
public:
  virtual float operator()(float A, float B) = 0;
protected:
  ~IFncPtr(){};  //Prevent using classes from deleting this
};

template <class T>
class CFncPtr: public IFncPtr
{
public:
  CFncPtr(T* Object, float (T::*FncPtr) (float, float))
  : mObject(Object)
  , mpFuncPtr(FncPtr)
  {}

  float operator()(float A, float B)
  {
    return (mObject->*mpFuncPtr)(A, B);
  }

protected:
  T* mObject;
  float (T::*mpFuncPtr) (float, float);
};

class CAdd
{
public:
  float FunctionAdd(float A, float B)
  {
    return A+B;
  }
};

class CSubtract
{
public:
  float FunctionSubtract(float A, float B)
  {
    return A-B;
  }
};

class CPerformOperator
{
public:
  CPerformOperator(IFncPtr* pFncPtr)
  : mpFncPtr(pFncPtr)
  { }

  void ChangeOperator(IFncPtr* pFncPtr)
  {
    mpFncPtr = pFncPtr;
  }

  float Execute(float A, float B)
  {
    return (*mpFncPtr)(A,B);
  }

private:
  IFncPtr* mpFncPtr;
};

int main(int argc, char** argv)
{
  CAdd Add;
  CSubtract Subtract;

  CFncPtr<CAdd> FncAdd(&Add, &CAdd::FunctionAdd);
  CFncPtr<CSubtract> FncSubtract(&Subtract, &CSubtract::FunctionSubtract);

  CPerformOperator Test(&FncAdd);
  cout << Test.Execute(1,2) << endl;
  Test.ChangeOperator(&FncSubtract);
  cout << Test.Execute(1,2) << endl;

  cout << "Also callable via: " << endl;
  cout << FncAdd(1,2) << endl;
  cout << FncSubtract(1,2) << endl;

  return 0;
}
