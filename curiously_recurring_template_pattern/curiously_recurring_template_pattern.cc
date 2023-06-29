#include <iostream>

// Base class using CRTP
template <typename Derived>
class Base {
public:
  void doSomething() {
    static_cast<Derived *>(this)->implementation();
  }
};

// Derived class 1
class Derived1 : public Base<Derived1> {
public:
  void implementation() {
    std::cout << "Derived1: Doing something specific to Derived1.\n";
  }
};

// Derived class 2
class Derived2 : public Base<Derived2> {
public:
  void implementation() {
    std::cout << "Derived2: Doing something specific to Derived2.\n";
  }
};

int main() {
  Derived1 d1;
  Derived2 d2;

  d1.doSomething(); // Calls implementation() in Derived1
  d2.doSomething(); // Calls implementation() in Derived2

  return 0;
}
