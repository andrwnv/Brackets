#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>

int o(0);
int c(0);
char opened[] = "{[(";
char closed[] = "}})";
std::stack <char> brackets;

bool check_brckts(char x){
      for( int j=0 ; j < strlen(closed) ; j++){
          if (x==opened[j]){
              return true;
          }
          else if (x==closed[j]){
              return false;
          }
      }
}

bool check(char x , char k){
    for ( int i=0 ; i<strlen(opened) ; i++){
        if (x==opened[i])
            o=i;
        else if (k==closed[i])
            c=i;
    }
    if (o == c){
        brackets.pop();
        return true;
    }
    else
        return false;
}

bool view(const char* string){
    for(int i=0 ; i<strlen(string) ; i++){
        if (check_brckts(string[i]))
            brackets.push(string[i]);
        else if (check_brckts(string[i])){
            if(check(brackets.top(), string[i]))
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return true;
}

int main(){
    std::string string;
    std::getline(std::cin, string);

    if (view(string.c_str()) and (brackets.empty()))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    system("pause");
    return 0;
}
