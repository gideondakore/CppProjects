#include "Casino.hpp"
#include <iostream>
#include <string> //std::string, std::getline
#include <ctime> //std::time
#include <cstdlib> //std::srand
#include <limits> //numeric_limits, streamsize

     
Casino::Casino(std::string name, double amount)
:name{name}, amount{amount}{}
     
std::ostream& operator<<(std::ostream& os, const Casino& rhs){
  os<<"\n"
    <<rhs.name<<" account info"
    <<"\n"
    <<"Balance: $"<<rhs.amount;
  return os;
}
     
void Casino::setName(std::string name){
  this->name = name;
}
     
std::string Casino::getName()const{
  return this->name;
}
     
void Casino::setAmount(double amount){
  this->amount = amount;
}
     
double Casino::getAmount()const{
  return this->amount;
}


void printRule(){
  std::cout<<"Rules rules rules"<<std::endl;
}

int randomNumber(int level = 1){
  int min{1};
  int max{level*10};
  int randNum{};
  std::srand(std::time(nullptr));
  randNum = std::rand() % max + min;
  return randNum;
}


int main(){
  Casino game;
  std::cout<<"Welcome to the world of Casino, player ;)"<<std::endl;
  
  printRule();
  
  std::string name{};
  double amount{};
  //const int NAME_LEN{60}, AMOUNT_LEN{24};
  
  std::cout<<"\nEnter your name: ";
  std::getline(std::cin, name);
  std::cout<<std::endl;
  game.setName(name);
  
  std::cout<<"Enter amount to bid: $";
  std::cin>>amount;
  std::cout<<std::endl;
  game.setAmount(amount);
  
  std::cin.clear();
  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  std::cout<<game<<std::endl;
  
  
return 0;
}
