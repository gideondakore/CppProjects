#ifndef _CASINO_H_
#define _CASINO_H_
#include <string>
#include <iostream>

class Casino {
  private:
     std::string name{};
     double amount{};
     int level{};
     double bid{};
     int luckyNumber{};
     double tempBid;
     
  public:
     Casino() = default;
     
     Casino(std::string, double);
     
     Casino& operator-(Casino& other);
     
     friend std::ostream& operator<<(std::ostream&, const Casino&);
     
     void setName(std::string);
     std::string getName()const;
     
     void setAmount(double);
     double getAmount()const; 
     
     void setLevel(int level);
     int getLevel()const;
     
     int randomNumberGen(int level = 1);
     
     void calcBalance(double);
     
     void setBid(double);
     double getBid()const;
     
     void setLuckyNumber(int);
     int getLuckyNumber()const;
     
};

#endif //_CASINO_H_
