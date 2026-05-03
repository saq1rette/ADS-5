// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "../include/alg.h"

int main() {
  std::string infix1 = "(2+2)*(3-1)";
  std::string postfix1 = infx2pstfx(infix1);
  std::cout << "Infix: " << infix1 << std::endl;
  std::cout << "Postfix: " << postfix1 << std::endl;
  std::cout << "Result: " << eval(postfix1) << std::endl;
  std::cout << std::endl;

  std::string infix2 = "100+200/2";
  std::string postfix2 = infx2pstfx(infix2);
  std::cout << "Infix: " << infix2 << std::endl;
  std::cout << "Postfix: " << postfix2 << std::endl;
  std::cout << "Result: " << eval(postfix2) << std::endl;
  std::cout << std::endl;

  std::string infix3 = "(10+2)*(3-1)/2";
  std::string postfix3 = infx2pstfx(infix3);
  std::cout << "Infix: " << infix3 << std::endl;
  std::cout << "Postfix: " << postfix3 << std::endl;
  std::cout << "Result: " << eval(postfix3) << std::endl;

  return 0;
}
