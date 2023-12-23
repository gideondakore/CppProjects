#include <iostream>
#include <utility> // std::pair
#include <vector> // std::vector
#include <string> // std::string
#include <cstdlib> //rand and srand
#include <ctime>   // time
#include <iomanip> // std::setw(), std::setfill() 
#include <algorithm> // std::next_permutation, std::sort
#include <tuple> //std::tuple, std::make_tuple, std::ignore, std::tie

 enum GameState {Rock = 1, Paper, Scissor, Unknown};
 
  std::ostream& operator<<(std::ostream& os, const GameState& gameState){
   switch(gameState){
   case Rock: os<<"Rock"; break;
   case Paper: os<<"Paper"; break;
   case Scissor: os<<"Scissor"; break;
   case Unknown: os<<"Unknown"; break;
   default: os<<"Wrong input!!";
  };
   
   return os;
 }
 
 std::istream& operator>>(std::istream& is, GameState& gameState){
  std::underlying_type_t<GameState>user_input;
  is>>user_input;
  
  switch(user_input){
   case Rock: gameState = GameState(user_input); break;
   case Paper: gameState = GameState(user_input); break;
   case Scissor: gameState = GameState(user_input); break;
   default: std::cout<<"user input is not a valid state.";
  };
  
  return is;
 }
 
 template<class It>
 struct GamePair{
   It first, second;
   
   It begin() const{return first;};
   It end() const{return second;};
 };
 
 
 std::tuple<GameState, GameState, GameState> get_winner(GameState arg1, GameState arg2){
  std::vector<std::tuple<GameState, GameState, GameState>> posVec {
   {Rock, Paper, Paper},
   {Rock, Scissor, Rock},
   {Paper, Scissor, Scissor}
  };
  
  for(auto &v: posVec){
    auto [val1, val2, str] = v;
    auto result = v;
    if(val1 == arg1 && val2 == arg2){
      result = v;
      return v;
    }
  }
   return std::make_tuple(arg1, arg2, Unknown);
 }
 
 void welcome_msg(){
   size_t setW{50};
   std::cout<< std::setfill('*');
   std::cout<< std::setw(setW) << "\tWelcome ";
   std::cout << "to Rock Paper Scissors";
   std::cout<< std::setw(setW) << std::left << " Game :)\t\t" << std::endl;
   std::cout<<std::endl;
  
   std::cout<<"Make a choice ;)\n"
           <<"1) Rock\n"
           <<"2) Paper\n"
           <<"3) Scissor\n"<<std::endl;
  
  };
int main(){
  
  int randNum {};
  int min {1};
  int max {3};
  int moduloCheck = max + 1;
  
  srand(time(nullptr));
  randNum = (rand() % max + min) % moduloCheck;
  
  GameState compGuestState = GameState(randNum);
  
  welcome_msg();
           
  GameState user_input;
  std::cout<<"Your choice: ";
  std::cin>>user_input;
  
  std::cout<<"Your choice is: "<< user_input
           <<"\nComputer choice is: "<< compGuestState
           <<std::endl;
  
  std::vector<GameState> vec = {compGuestState, user_input};
  GamePair<std::vector<GameState>::iterator> range{vec.begin(), vec.end()-1};
  std::sort(range.begin(), range.end()+1);
 
  const auto [arg1, arg2, winner] = get_winner(*range.first, *range.second);
  if(winner != Unknown){
    std::cout<<winner<<" Wins :)"<<std::endl;
    winner == compGuestState ? std::cout<<"You Loose :(\n" : std::cout<<"Hooray...You Win\n";
  }else{
    std::cout<<winner<<" Winner, play again :("<<std::endl;
  }
     
  return 0;
}
