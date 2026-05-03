// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>

#include "../include/alg.h"

int main() {
  std::string infix = "(2+2)*(3-1)";
  std::string postfix = infx2pstfx(infix);
  std::cout << "Infix: " << infix << std::endl;
  std::cout << "Postfix: " << postfix << std::endl;
  std::cout << "Result: " << eval(postfix) << std::endl;
  return 0;
}
