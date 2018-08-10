#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include<stack>

int balance(0);
char opened[] = "{[(";
char closed[] = "}})";

bool check_o(char x){
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
}

bool view(char x[]){
    stack <char> brackets;
    for(int i=0 ; i<strlen(x) ; i++){
        if (check_c(x[i])){
            if (balance==-1)
                return false;
        }
        else if (check_o(x[i])){
            brackets.push(x[i]);
        }
    }
}

int main(){
    char string[100];
    gets (string);

    if (view(string))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    system("pause");
    return 0;
}
