#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include<stack>

int balance(0);
char opened[] = "{[(";
char closed[] = "}})";
std::stack <char> brackets;

bool check_brckts(char x){
      for( int j=0 ; j < strlen(closed) ; j++){
          if (x[i]==opened[j]){
              return true;
          }
          else if (x[i]==closed[j]){
              return false;
          }
      }
}

/*bool check_o(char x){
    for(int i=0 ; i<strlen(opened) ; i++){
       if (x==opened[i]){
           ::balance++;
           return true;
       }
    }
}

bool check_c(char x){
    for(int i=0 ; i<strlen(closed) ; i++){
       if (x==closed[i]){
           ::balance--;
           return false;
       }
    }
    return
}*/

/*bool check(std::stack<char>& x , char k){
    for( int i=0 ; i<strlen(closed) ; i++){
        if(x)
    }
}*/

bool view(const char* string){
    for(int i=0 ; i<strlen(string) ; i++){
        if (check_c(string[i])){
            if (balance==-1)
                return false;
            else if (check(brackets, string[i]))
        }
        else if (check_o(string[i]) and (balance > 0)){
            brackets.push(string[i]);
        }
        else if (check_c(string[i])){
            if (check(brackets, string[i]))
        }
    }
    return true;
}

int main(){
    std::string string;
    std::getline(std::cin, string);

    if (view(string.c_str()))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    system("pause");
    return 0;
}
