# CPP-Examples
[![Build Status](https://travis-ci.org/maartentamboer/CPP-Examples.svg?branch=master)](https://travis-ci.org/maartentamboer/CPP-Examples)

## How to build
- Go to the root directory of the project
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

Project has been compiled with Apple LLVM version 7.3.0 (clang-703.0.29)

## Contents
#### MemberFncPtr
Example of Member function pointers.  

#### VectorUniquePtr
Example of a vector with unique pointers to a class. Uses the `std::make_unique` from the new C++14 standard. An alternative that works with C++11 is also shown.

#### GenericFncPtr
Some magic using C++ Member function pointers with templates and an interface class.

#### Future
Tests using std::future and std::async to calculate average of a vector. The amount of parallel threads is changed by a variable and the results have been plotted. Note that this test was performed on a quad core machine (2,5 GHz Intel Core i5).