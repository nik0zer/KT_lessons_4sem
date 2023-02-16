#include <iostream>

#include "bank.h"

int main() 
{
  std::cout << "Hello world" << std::endl;
  
  std::unique_ptr<Account> acc1(Bank::createPremium("vasya"));
  std::unique_ptr<Account> acc2(Bank::create("masha"));
  

  std::cout<<*acc1<<"\n"<<*acc2<<"\n";
  
  std::shared_ptr<Money> m1 = acc1->take(50, "RUB");
  
  std::cout<<*acc1<<std::endl;
  
  std::shared_ptr<Money> m2 = acc1->take(60, "RUB");
  
  std::cout<<*acc1<<std::endl;
  
  acc1->put(m2);
  
  std::cout<<*acc1<<std::endl;
  std::cout<<"put "<<acc1->put(m2)<<std::endl;
  std::cout<<*acc1<<std::endl;
  std::cout<<"m1 "<<*m1<<std::endl;  
}