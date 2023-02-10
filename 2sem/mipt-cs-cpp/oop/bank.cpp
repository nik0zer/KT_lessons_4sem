#include "bank.h"

#include <iostream>

bool Account::validate(int amount, std::string currency) {
  if (amount > this->amount_) {
    std::cerr << "No funds" << std::endl;
    return false;
  }
  if (currency != this->currency_) {
    std::cerr << "Wrong currency" << std::endl;
    return false;
  }
  return true;
}

void Account::print() {
  std::cout << this->name_ << " " << this->amount_ << " " << this->currency_
            << std::endl;
}

Money& Account::take(int amount, std::string currency) {
  Money* null_money = new Money(0, currency);
  if (!validate(amount, currency)) {
    return *null_money;
  }

  Money* money = new Money(amount, currency_);
  this->amount_ -= amount;
  return *money;
}

bool Account::put(Money& money) {
  if (money.currency_ != this->currency_ || !money.usage_) {
    return false;
  }
  this->amount_ += money.value_;
  money.usage_ = false;
  return true;
}

Account* Bank::create(std::string name) { return new RUBAccount(100, name); }

Account* Bank::createPremium(std::string name) {
  return new RUBAccountWithOverdraft(100, name, 50);
}

bool RUBAccountWithOverdraft::validate(int amount, std::string currency) {
  if (amount - this->amount_ > _limit) {
    std::cerr << "No funds" << std::endl;
    return false;
  }
  if (currency != this->currency_) {
    std::cerr << "Wrong currency" << std::endl;
    return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream &out, Money &money)
{
  out<<money.value_<<" "<<money.currency_;
  return out; 
}

std::ostream& operator<< (std::ostream &out, const Account &account)
{
  out<<account.name_<<" "<<account.amount_<<" "<<account.currency_;
  return out;
}