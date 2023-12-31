#include "Casino.hpp"
#include <iostream>
#include <string> //std::string, std::getline
#include <ctime> //std::time
#include <cstdlib> //std::srand
#include <limits> //numeric_limits, streamsize
#include <iomanip> //std::setw(), std::setfill(), std::left
#include <cctype> //std::tolower()
#include <sstream> //std::istringstream

     
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

void Casino::setLevel(int level){
 this->level = level;
}

int Casino::getLevel()const{
 return this->level;
}

int Casino::randomNumberGen(int level){
  int min{1};
  int max{level*10};
  int randNum{};
  std::srand(std::time(nullptr));
  randNum = std::rand() % max + min;
  return randNum;
}

void Casino::calcBalance(double val){
  this->amount += val;
}

Casino& operator*(Casino& lhs, double rhs){
  lhs.calcBalance(lhs.getAmount() * rhs);
  return lhs;
}

void printRule(){
  std::cout<<std::setfill('*')<<std::setw(50)
           <<" These "
           <<"are the rules of the "
           <<std::setfill('*')<<std::setw(50)<<std::left
           <<"game "
           <<std::endl;
  std::cout<<"Do you want try your luck? (y/n)"<<std::endl;
}

void printRandNumberMsg(Casino casino){
  std::cout<<"Predict the random number between 1-"<<casino.getLevel() * 10<<std::endl;
}

void clearStreamBuffer(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char yesOrNo(char response){
 char res;
 do{
  
  if(response == 'y'){
    res = response;
    break;
  }else if(response == 'n'){
    res = response;
    break;
  }else{
    std::cout<<"Invalid input. Please enter 'y' or 'n' "<<std::endl;
  }
  
 }while(response != 'y' && response != 'n');
 
 return res;
  
}

int levelSelector(){
  int level{};
  bool continueLoop{false};
  do{
    std::cout<<"select a game level. 1-10:\nlevel: "<<std::endl;
  
    if(std::cin>>level && level > 0 && level <= 10){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }else{
      continueLoop = true;
      std::cout<<"Game level must be number and greater than 0 but less than or equal 10.\n";
    }
  }while(continueLoop);
  
  return level;
  
}


int validateUserInput(){
   int user_input{};
   int validator{};
   bool continueLoop{false};
   do{
     if(std::cin>>user_input && user_input > 0 && user_input <= 10){
       validator = user_input;
     }else{
      std::cout<<"Invalid input. Your guest must be a number and it should be greater than 0 but less than or equal to 10";
      continueLoop = true;
     }
     clearStreamBuffer();
   }while(continueLoop);
   
   return validator;
}

std::string outCome(int user_guest){
//game.randomNumberGen()
  if(user_guest == 1){
    return std::string("win");
  }
  
  return std::string("lose");
}

int main(){
  Casino game;
  std::cout<<"Welcome to the world of Casino, player ;)"<<std::endl;
  
  std::string name{};
  double amount{};
  char response{};
  //int gameLevel{};
  double bidAmount{};
  
  
  std::cout<<"\nEnter your name: ";
  std::getline(std::cin, name);
  std::cout<<std::endl;
  game.setName(name);
  
  std::cout<<"Enter amount to bid: $";
  std::cin>>amount;
  std::cout<<std::endl;
  game.setAmount(amount);
  
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  
  printRule();
  
  
  response = std::cin.get();
  response = std::tolower(response);
  
  clearStreamBuffer();
  
  response = yesOrNo(response);
  
  if(response == 'n'){
    return 0;
  }
  
  int gameLevel = levelSelector();
  game.setLevel(gameLevel);
  
  //int randNumber = game.randomNumberGen();
  int randNumber = 1;
  
  printRandNumberMsg(game);
  
  
  int user_guest = validateUserInput();
  std::string outcome = outCome(user_guest);
  
  
  if(outcome == "win"){
     game *= 2; //overloaded * operator
     std::cout<<"Hooray!!!... You win "<<game.getLevel()*2<<" time "<<"your current balance\n";
     std::cout<<game<<std::endl;
     std::cout<<"Do you want to continue playing? (y/n)\n";
     response = yesOrNo(response);
     clearStreamBuffer();
  }else{
     std::cout<<"Sorry. You lose "<<game.getLevel()*2<<" minus "<<"your current balance\n";
     std::cout<<game<<std::endl;
     std::cout<<"Do you want to continue playing? (y/n)\n";
     response = yesOrNo(response);
     clearStreamBuffer();
  }
  
  
  if(user_guest == randNumber){
     game = game * 2;
     std::cout<<"Hooray!!!... You win "<<game.getLevel()*2<<" time "<<"your current balance\n";
     std::cout<<game<<std::endl;
     std::cout<<"Do you want to continue playing? (y/n)\n";
     response = yesOrNo(response);
     clearStreamBuffer();
     
     if(response == 'y'){
     
     }else{
      return 0;
     }
     
     do{
     std::cout<<"Enter amount to bid: $";
     std::cin>>bidAmount;
     clearStreamBuffer();
     if(bidAmount <= game.getAmount()){
       printRandNumberMsg(game);
       continue;
     }else{
       std::cout<<"Bid amount must be equal or less than "<<game.getAmount()<<std::endl;
       std::cout<<"Do you want to continue playing? (y/n)\n";
       response = std::cin.get();
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       }
     }while(bidAmount > game.getAmount() || (response != 'n' && response == 'y'));
     
  }
  
  
  
  
return 0;
}
