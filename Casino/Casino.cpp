#include "Casino.hpp" //Casino
#include <iostream>
#include <string> //std::string, std::getline, substr(), find_first_not_of, find_last_not_of
#include <ctime> //std::time
#include <cstdlib> //std::srand
#include <limits> //numeric_limits, streamsize
#include <iomanip> //std::setw(), std::setfill(), std::left, std::setprecision, std::fixed
#include <cctype> //std::tolower(), std::toupper()
#include <sstream> //std::istringstream
#include <cstddef> //size_t

enum class GameState{Win, Lose};
     
Casino::Casino(std::string name, double amount)
:name{name}, amount{amount}{}

Casino& Casino::operator-(Casino& rhs){
  
  int decimalPointBid = Casino::checkDecimals(rhs.bid);
  int decimalPointAmount = Casino::checkDecimals(this->amount);
  
  rhs.bid *= pow(10, decimalPointBid);
  this->amount *= pow(10, decimalPointAmount);
  double results = (this->amount - rhs.bid) / pow(10, 2);
  rhs.bid /= pow(10,2);
  
  this->amount = results;
  
  return rhs; 
}
     
std::ostream& operator<<(std::ostream& os, const Casino& rhs){
  os<<std::setfill('*')<<std::setw(50)<<std::right<<" ACCOUNT";
  os<<std::setfill('*')<<std::setw(50)<<std::left<<" DETAILS "
                       <<"\nName: "<<rhs.name<<"\n"
                       <<"Main balance: $"<<rhs.amount;
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

void Casino::setBid(double bid){
  this->bid = bid;
}

double Casino::getBid()const{
  return this->bid;
}

void Casino::setLuckyNumber(int luckyNumber){
  this->luckyNumber = luckyNumber;
}

int Casino::getLuckyNumber()const{
  return this->luckyNumber;
}

int Casino::checkDecimals(double value){
  std::ostringstream oss;
  oss << std::setprecision(2) << std::fixed << value;
  std::string valStr = oss.str();
  size_t dotPos = valStr.find('.');
  
  if(dotPos != std::string::npos)
    return valStr.size() - dotPos -1;
  
  return 0;
  
}

Casino& operator*(Casino& lhs, double rhs){
  lhs.calcBalance(lhs.getBid() * rhs);
  return lhs;
}


void welcomMsg(){
       std::cout << "\n=========================================================================================================";
        std::cout<< "\n W       W       W  EEEEEEEEE  LL           CCCCC   OOOOOOOO       M       M      EEEEEEEEE       ";
        std::cout<< "\n  W     W W     W   EE         LL         CC       OO      OO     M M     M M     EE              ";
        std::cout<< "\n   W   W   W   W    EEEEEEE    LL        CC        OO      OO    M   M   M   M    EEEEEEE         ";
        std::cout<< "\n    W W     W W     EE         LL         CC       OO      OO   M     M M     M   EE              "; 
        std::cout<< "\n     W       W      EEEEEEEEE  LLLLLLLL     CCCCC   OOOOOOOO   M       M       M  EEEEEEEEE       ";
        std::cout<<std::endl;
        std::cout<< "\n\t\t\t\t\t TTTTTTTT   OOOOOOOO    ";
        std::cout<< "\n\t\t\t\t\t    TT     OO      OO   ";
        std::cout<< "\n\t\t\t\t\t    TT     OO      OO   ";
        std::cout<< "\n\t\t\t\t\t    TT     OO      OO   ";
        std::cout<< "\n\t\t\t\t\t    TT      OOOOOOOO    ";
        std::cout<<std::endl;
	std::cout << "\n\t\t   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	std::cout << "\n\t\t CC          A  A      SS             III     NN N   NN   OO      OO    ";
	std::cout << "\n\t\tCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
	std::cout << "\n\t\t CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
	std::cout << "\n\t\t   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	std::cout << "\n=========================================================================================================\n\n";
}
void printRule(){
  std::cout<<std::setfill('*')<<std::setw(50)
           <<" THESR "
           <<"ARE THE RULES OF THE "
           <<std::setfill('*')<<std::setw(34)<<std::left
           <<"GAME "
           <<std::endl;
}

void printRandNumberMsg(Casino casino){
  
  std::cout<<"Predict the random number between 1-"<<casino.getLevel() * 10<<": ";
}

void clearStreamBuffer(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char yesOrNo(){
 char response{};
 do{
  response = std::cin.get();
  response = std::tolower(response);
  clearStreamBuffer();
  if(response == 'y'){
    return response;
  }else if(response == 'n'){
    return response;
  }else{
    std::cout<<"Invalid input. Please enter 'y' or 'n' "<<std::endl;
    std::cout<<"Do you want to continue playing? (y/n): ";
  }
  
 }while(response != 'y' && response != 'n');
  
  return response;
}

int levelSelector(){
  int level{};
  bool continueLoop{false};
  do{
    std::cout<<"select a game level. 1-10\nlevel: ";
  
    if(std::cin>>level && level > 0 && level <= 10){
      clearStreamBuffer();
      return level;
    }else{
      std::cout<<"Game level must be a number and greater than 0 but less than or equal to 10\n";
      clearStreamBuffer();
      continueLoop = true;
    }
  }while(continueLoop);
  
  return level;
  
}

int validateUserGuestNumber(Casino& casino){
   int user_input{};
   int validator{};
   bool continueLoop{false};
   do{
     if(std::cin>>user_input && user_input > 0 && user_input <= (casino.getLevel()*10)){
       clearStreamBuffer();
       validator = user_input;
     }else{
      std::cout<<"Invalid input. Your guest must be a number and it should be greater than 0 but less than or equal to "<<casino.getLevel()*10<<std::endl;
      
      clearStreamBuffer();
      continueLoop = true;
     }
   }while(continueLoop);
   
   return validator;
}

GameState outCome(int user_guest, Casino& casino){
  casino.setLuckyNumber(casino.randomNumberGen(casino.getLevel()));
  if(user_guest == casino.getLuckyNumber()){
    return GameState::Win;
  }
  
  return GameState::Lose;
}

char outcomeMsg(GameState outcome, Casino& casino){
  char response{};
  if(outcome == GameState::Win){
     casino = casino * (casino.getLevel() * 2); //global overloaded * operator
     std::cout<<"Hooray!!!...You guest the lucky number which is "<<casino.getLuckyNumber()
              <<", You won "<<casino.getLevel()*2<<" time "<<"your current bidding value (i.e "<<(casino.getBid() * casino.getLevel() * 2)<<")\n\n";
     std::cout<<casino<<std::endl;
     std::cout<<"\nDo you want to continue playing? (y/n): ";
     
     response = yesOrNo();
    
     return response;
  }else{
     casino = casino - casino; //member overloaded - operator
     
     std::cout<<"Sorry. You lose, the lucky number was "<<casino.getLuckyNumber()<<", $"
              <<casino.getBid()<<" has been deducted from "<<"your main balance\n\n";
     std::cout<<casino<<std::endl;
     std::cout<<"\nDo you want to continue playing? (y/n): ";
   
     response = yesOrNo();
     
     return response;
  }
    
}

bool bidAmount(Casino& casino){
    double bidAmount{};
    char response{};
    do{
     std::cout<<"Enter amount to bid: $";
     
     if(std::cin>>bidAmount){
       clearStreamBuffer();
       if( (casino.getAmount() >= bidAmount) && (casino.getAmount() > 0.00) && (bidAmount > 0.00) ){
         casino.setBid(bidAmount);
         return true;
       }else{
         std::cout<<std::setprecision(2)<<std::fixed;
         double getVal = (casino.getAmount() != 0 ? casino.getAmount() : 0);
         if(getVal != 0){
             std::cout<<"\nInsufficient amount, Bidding amount must be greater than $0.00 and at most $"
                      <<getVal;
         }else{
            std::cout<<"\nInsufficient amount. $"
                     <<getVal
                     <<" is not a valid bid amount";
        }
        
        std::cout<<". Wallet info:\n\n"
                 <<casino
                 <<"\n\nEnter a sufficient amount to continue.\n"
                 <<"Do you want to continue playing? (y/n): ";
                  
        response = yesOrNo();           
       }
     }else{
       std::cout<<"Invalid input. Enter valid amount\n";
       clearStreamBuffer();
     }
     
    }while(response == 'y' || response != 'n');
    
  return false;
}

void quitCasino(){
  std::cout<<"Casino game quitted successfully..."<<std::endl;
}

void getUserName(Casino& casino){
   std::string name{};
   bool continueLoop{false};
  do{
    std::cout<<"\nEnter your name: ";
    std::getline(std::cin, name);
    size_t firstNotOf = name.find_first_not_of(" \t\n\r");
    size_t lastNotOf = name.find_last_not_of(" \t\n\r");
    if(firstNotOf != std::string::npos && lastNotOf != std::string::npos){
    name = name.substr(firstNotOf, lastNotOf - firstNotOf + 1);
    name.at(0) = std::toupper(name.at(0));
    casino.setName(name);
    continueLoop = false;
    }else{
      std::cout<<"Please name is required"<<std::endl;
      continueLoop = true;
    }
  }while(continueLoop);
}

int main(){
  Casino game;
  
  char response{};
  double deposit{};
  welcomMsg();
  printRule();
  
  getUserName(game);
  
  bool continueLoop{false};
  do{
    std::cout<<"Enter amount to deposit to start: $";
    if(std::cin>>deposit){
      clearStreamBuffer();
      game.setAmount(deposit);
      continueLoop = false;
    }else{
      std::cout<<"Invalid amount. Please enter a valid amount\n";
      clearStreamBuffer();
      continueLoop = true;
    }
  }while(continueLoop);
  
  int gameLevel = levelSelector();
  game.setLevel(gameLevel);
   
  bool res = bidAmount(game);
  if(!res){
    quitCasino();
    return 0;
  }
   
  std::cout<<"Do you want try your luck? (y/n): ";
  response = yesOrNo();
  
  
  if(response == 'n'){
    quitCasino();
    return 0;
  }
  
  printRandNumberMsg(game);
  
  int user_guest = validateUserGuestNumber(game);
  std::cout<<std::endl;
  GameState outcome = outCome(user_guest, game);
  response = outcomeMsg(outcome, game);
  
  if(response == 'y'){
   bool validatedAmount{};
  do{
     validatedAmount = bidAmount(game);
     if(validatedAmount){
       printRandNumberMsg(game);
       user_guest = validateUserGuestNumber(game);
       std::cout<<std::endl;
       GameState outcome = outCome(user_guest, game);
       response = outcomeMsg(outcome, game);
     }else{
       quitCasino();
       return 0;
      }
   }while(response != 'n' && response == 'y'); 
 }  
 
 quitCasino();
return 0;
}
