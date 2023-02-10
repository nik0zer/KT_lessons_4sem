#include <string>

class Money
{
 private:
  int value_;
  bool usage_;
  std::string currency_;
  Money(const Money &money) = delete;
  friend std::ostream& operator<<(std::ostream &out, Money& money);


 protected:
  Money(int value, std::string currency) : value_(value), currency_(currency), usage_(true){};

 private:
  friend class Account;
};

class RUBMoney : Money
{
 protected:
  RUBMoney(int value) : Money(value, "RUB"){};
};

class Account 
{
 private:
  const std::string name_;
  // disable copy and assignment to make a copy of initial object
  Account(const Account &acc) = delete;
  Account &operator=(const Account &) = delete;
  friend std::ostream& operator<< (std::ostream &out, const Account &account);

 protected:
  int amount_;
  std::string currency_;
  Account(int amount, std::string currency, std::string name)
      : amount_(amount), currency_(currency), name_(name){};
  virtual bool validate(int amount, std::string currency);

 public:
  void print();
  Money& take(int amount, std::string currency);
  bool put(Money& money);
  const std::string &getName() const { return name_; };
};

class RUBAccount : public Account {
 protected:
  RUBAccount(int amount, std::string name) : Account(amount, "RUB", name){};

 private:
  friend class Bank;
};

class RUBAccountWithOverdraft : public RUBAccount 
{
 private:
  int _limit;
  friend class Bank;
  RUBAccountWithOverdraft(int amount, std::string name, int limit)
      : RUBAccount(amount, name), _limit(limit){};
  bool validate(int amount, std::string currency) override;
};

class Bank 
{
 public:
  static Account *create(std::string name);
  static Account *createPremium(std::string name);
};