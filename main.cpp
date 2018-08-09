#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

bool check_o(char x){
    char opened[] = "{[(";

    for(int i=0 ; i<strlen(opened) ; i++){
       if (x==opened[i]){
           return true;
       }
    }
}

bool check_c(char x){
    char closed[] = "}})";

    for(int i=0 ; i<strlen(closed) ; i++){
       if (x==closed[i]){
           return false;
       }
    }
}

bool view(char x[]){
    int balance = 0;

    for(int i=0 ; i<strlen(x) ; i++){
        if (check_o(x[i]))
            balance++;
        else if (check_c(x[i]) && balance>0)
            balance--;
        else
            return false;
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
