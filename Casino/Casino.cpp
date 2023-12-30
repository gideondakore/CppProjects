#include "Casino.hpp"
#include <iostream>
#include <string> //std::string
#include <ctime> //std::time
#include <cstdlib> //std::srand

     
Casino::Casino(std::string name, double amount)
:name{name}, amount{amount}{}
     
std::ostream& operator<<(std::ostream& os, const Casino& rhs){
  os<<"\n"
    <<rhs.name<<" account info"
    <<"\n"
    <<"Balance: "<<rhs.amount;
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
  std::cout<<"Welcome to the world of Casino, plaayer ;)"<<std::endl;
  
  printRule();
  
  std::string name{};
  double amount{};
  
  std::cout<<"Enter your name: ";
  std::cin>>name;
  std::cout<<std::endl;
  game.setName(name);
  
  std::cout<<"Enter amount to bid: $";
  std::cin>>amount;
  std::cout<<std::endl;
  game.setAmount(amount);
  
  std::cout<<game<<std::endl;
return 0;
}
