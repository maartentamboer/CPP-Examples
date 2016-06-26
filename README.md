# CPP-Examples
[![Build Status](https://travis-ci.org/maartentamboer/CPP-Examples.svg?branch=master)](https://travis-ci.org/maartentamboer/CPP-Examples)

##How to build
- Go to the root directory of the project
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

Project has been compiled with Apple LLVM version 6.0 (clang-600.0.56) (based on LLVM 3.5svn)

##Contents
#### MemberFncPtr
Example of Member function pointers.  

#### VectorUniquePtr
Example of a vector with unique pointers to a class. Uses the `std::make_unique` from the new C++14 standard. An alternative that works with C++11 is also shown.

#### GenericFncPtr
Some magic using C++ Member function pointers with templates and an interface class.
