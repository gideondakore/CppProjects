#include <iostream>
#include <utility> // std::pair
#include <vector> // std::vector
#include <string> // std::string
#include <cstdlib> //rand and srand
#include <ctime>   // time
#include <iomanip> // std::setw(), std::setfill() 
#include <algorithm> // std::next_permutation, std::sort
#include <tuple> //std::tuple, std::make_tuple, std::ignore, std::tie

 /* GameState enum */
 enum GameState {Rock = 1, Paper, Scissor, Unknown};
  
 /* Overloading the << operator for GameState */ 
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
 
 /* Overloading the >> operator for GameState */
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
 
 
 template<class It> //'It' serve as a iterator for GamePair members
 struct GamePair{  // GamePair Struct
   It first, second;
   
   It begin() const{return first;};
   It end() const{return second;};
 };
 
 /* get_winner return a tuple containing information about the winner and return 'Unknown' if both state are the same or invalid */
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
 
 /* Print a welcome message and about the game */
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
  int min {1}; // minimum random number that can be generated 
  int max {3}; // maximum random number that can be generated
  int moduloCheck = max + 1; // to make sure the number generated is not greater than the maximum number (i.e 3)
  
  srand(time(nullptr)); //seeding the srand with a nullptr
  randNum = (rand() % max + min) % moduloCheck; //Random number generated between 1 and 3 and not greater than 3;
  
  GameState compGuestState = GameState(randNum); //Storing the random guess state to a variable
  
  welcome_msg(); // print the welcome message and about the game;
           
  GameState user_input; // is to store the user input.
  std::cout<<"Your choice: ";
  std::cin>>user_input; // uses the custom >> operator to extract the user input into user_input;
  
  /* uses the custom << operator to insert user_input and compGuestState to the stream */
  std::cout<<"Your choice is: "<< user_input
           <<"\nComputer choice is: "<< compGuestState
           <<std::endl;
  
  
  std::vector<GameState> vec = {compGuestState, user_input}; // vector to store both random Gamestate generated and user choice GameState
  
  /* range is an instance of GamePair Struct that contain the iterator to it member. The 'vec.end()-1',is to make sure iterator is NOT pointing to address after the last element in the vector*/
  GamePair<std::vector<GameState>::iterator> range{vec.begin(), vec.end()-1};
  
  /* Sorting it from smaller GameState value to bigger state. The range.end()+1 is to compensate the 'vec.end()-1' from the vector. This is done to make sure sort algorithm iterator range.end()+1 is pointing to the address after the last element in the vector 'vec'*/ 
  std::sort(range.begin(), range.end()+1);
 
  const auto [arg1, arg2, winner] = get_winner(*range.first, *range.second); // calls get_winner() and store the return tuple values in arg1,arg2 and winner
  if(winner != Unknown){
    std::cout<<winner<<" Wins :)"<<std::endl;
    winner == compGuestState ? std::cout<<"You Loose :(\n" : std::cout<<"Hooray...You Win\n";
  }else{
    std::cout<<winner<<" Winner, play again :("<<std::endl;
  }
     
  return 0;
}
