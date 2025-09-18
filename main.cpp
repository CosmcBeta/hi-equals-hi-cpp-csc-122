#include <iostream>

#include "src/hello.hpp"

int main() {
  // Your driver program goes here
  std::cout << strcmp("cater", "cat") << "\n";
  std::cout << std::string("12").length() << "\n";
  strcmp_case_insensitive("eee","eee");
  std::cout << strcmp_case_insensitive("a", "B") << "\n";
  std::cout << strcmp("a", "B") << "\n";
  std::cout << strcmp("B", "a") << "\n";
}
