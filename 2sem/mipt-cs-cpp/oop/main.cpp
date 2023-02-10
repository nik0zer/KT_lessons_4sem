#include <iostream>

#include "bank.h"

int main() {
  std::cout << "Hello world" << std::endl;
  Account* acc1 = Bank::createPremium("vasya");
  Account* acc2 = Bank::create("masha");
  std::cout<<*acc1<<"\n"<<*acc2<<"\n";
  Money& m1 = acc1->take(50, "RUB");
  std::cout<<*acc1<<std::endl;
  Money& m2 = acc1->take(60, "RUB");
  std::cout<<*acc1<<std::endl;
  acc1->put(m2);
  std::cout<<*acc1<<std::endl;
  std::cout<<acc1->put(m2)<<std::endl;
  std::cout<<*acc1<<std::endl;
  std::cout<<m1<<std::endl;

  delete acc1;
  delete acc2;
  delete &m1;
  delete &m2;
  
}