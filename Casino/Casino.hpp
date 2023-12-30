#ifndef _CASINO_H_
#define _CASINO_H_
#include <string>
#include <iostream>

class Casino {
  private:
     std::string name{};
     double amount{};
     
  public:
     Casino() = default;
     
     Casino(std::string, double);
     
     friend std::ostream& operator<<(std::ostream&, const Casino&);
     
     void setName(std::string);
     
     std::string getName()const;
     
     void setAmount(double);
     
     double getAmount()const; 
};

#endif //_CASINO_H_
