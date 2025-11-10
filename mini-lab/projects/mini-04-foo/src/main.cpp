#include <iostream>
#include "ok.hpp"

int main(int argc, char** argv) {
  std::cout << "Hello from " << (argc > 0 ? argv[0] : "mini") << "\n";
  std::cout << "add(2, 3) = " << add(2, 3) << "\n";
  return 0;
}
