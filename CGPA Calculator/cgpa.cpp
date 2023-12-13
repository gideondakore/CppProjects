#include <iostream>
#include <cctype>
#include <typeinfo>
#include <string>
#include <cstring>

enum Grades {A = 40, A_MINUS = 37, B_PLUS = 33, B = 30, B_MINUS = 27, C_PLUS = 23, C = 20, C_MINUS = 17, D_PLUS = 13, D = 10, D_MINUS= 7, F = 0};

std::string gradeCalc(double mark){
 if(mark >= 97)
   return "A+";
 else if(mark >= 93)
   return "A";
 else if(mark >= 90)
   return "A-";
 else if(mark >= 87)
   return "B+";
 else if(mark >= 83)
   return "B";
 else if(mark >= 80)
   return "B-";
 else if(mark >= 77)
   return "C+";
 else if(mark >= 73)
   return "C";
 else if(mark >= 70)
   return "C-";
 else if(mark >= 67)
   return "D+";
 else if(mark >= 65)
   return "D";
 else if(mark < 65)
   return "D-";
 else
  return "F";
}

double gpaCalc(int numOfCourses, int &totalCredit){
  totalCredit = 0;
  char response;
  std::string grade{};
  double mark {0.0};
  const char* gr;
  Grades gradeValue;
  double gradePoints {0};
  int unitCredit = 1;
  //int totalCredit{0};
  double gpa{0.0};
  std::cout<<"Would you like to provide your score in grade[A-F](i.e y) or percentage value[1-100](i.e n): (y/n): ";
  std::cin>>response;
  
  for(int i = 0; i < numOfCourses; ++i){
      if(std::tolower(response) == 'y'){
        std::cout<<"Enter grade for course "<<i+1<<": and the correspondent credit hour(s) value: " ;
        std::cin>>grade>>unitCredit;
        gr = grade.c_str();
      }else if(std::tolower(response) == 'n'){
        std::cout<<"Enter mark for course "<<i+1<<": and the correspondent credit hour(s) value: " ;
        std::cin>>mark>>unitCredit;
        grade = gradeCalc(mark);
        gr = grade.c_str();
      }else{
        return 1;
      }
      
      totalCredit += unitCredit;
      
      std::string str;
      char gradeChar {(char)(toupper(static_cast<int>(gr[0])))};
      str += gradeChar;
      
      if(grade.length() > 1){
       str += grade[1];
      }
       
      if(std::isalpha(str[0]) || std::isalpha(str[1])) {
          
        if(str == "A+" || str == "A")
          gradeValue = A;
        else if(str == "A-")
          gradeValue = A_MINUS;
        else if(str == "B+")
          gradeValue = B_PLUS;
        else if(str == "B")
          gradeValue = B;
        else if(str == "B-")
          gradeValue = B_MINUS;
        else if(str == "C+")
          gradeValue = C_PLUS;
        else if(str == "C")
          gradeValue = C;
        else if(str == "C-")
          gradeValue = C_MINUS;
        else if(str == "D+")
          gradeValue = D_PLUS;
        else if(str == "D")
          gradeValue = D;
        else if(str == "D-")
          gradeValue = D_MINUS;
        else if(str == "F")
          gradeValue = F;
        else{
          std::cout<<"Wrong input"<<std::endl;
          return 1;
        }
          
       gradePoints += (static_cast<double>(gradeValue)/10) * unitCredit;
      }
      
   }  
  gpa = gradePoints / totalCredit;
  return gpa;
}

int main() {
 
 int AGS = 1;
 int numOfCourses = 1;
 double gpa{0.0};
 double cgpa{0.0};
 int *totalCredit {nullptr};
 totalCredit = new int;
 
 std::cout<<"Hi, there welcome to Academic Performance Metric (APM) or Academic Grading System (AGS)"<<std::endl;
 std::cout<<"Which grading system do you prefer"<<std::endl
          <<"1) GPA"<<std::endl
          <<"2) CGPA"<<std::endl
          <<"3) CWA"<<std::endl;
 std::cout<<"Choose between 1-3: ";
 std::cin>>AGS;
 
 std::cout<<"What is the number of courses taken: ";
 std::cin>>numOfCourses;
 
 if (AGS == 1){
   gpa = gpaCalc(numOfCourses, *totalCredit);
   std::cout<<"Your GPA Score = "<<gpa<<std::endl;
   
 }
 
 if (AGS == 2){
  double weightGPA = gpaCalc(numOfCourses, *totalCredit);
  cgpa = weightGPA / static_cast<double>(*totalCredit);
  std::cout<<"Your CGPA Score = "<<cgpa<<std::endl;
 }

 delete totalCredit;
return 0;
}
