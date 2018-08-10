#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>

std :: stack <char> o_brackets;

bool search_brckts(const char* string){
      char opened[] = "{[(";
      char closed[] = "}})";
      int c=0;
      for ( int i = 0 ; i < strlen(string) ; i++ ){
          for ( int j = 0 ; j < strlen(opened) ; j++ ){
              if ( opened[j] == string[i] or ( opened[j] == string[i] ) )
                  c++;
          }
      }
      if ( c > 0 )
          return true;
      else
          return false;
}

bool check_closed_brckts(const char* string){
    int balance = 0;
    char closed[] = "}})";
    for ( int i = 0 ; i < strlen(string) ; i++ ){
        for ( int j = 0 ; j < strlen(closed) ; j++ ){
            if ( string[i] == closed[j] and (balance == 0) )
                balance--;
        }
    }
    if ( balance < 0 )
        return true;
    else
        return false;
}

/*bool check(char x , char k){
    char opened[] = "{[(";
    char closed[] = "}})";
    int o , c;
    for ( int i=0 ; i<strlen(opened) ; i++){
        if (x==opened[i])
            o=i;
        else if (k==closed[i])
            c=i;
    }
    if (o == c){
        o_brackets.pop();
        return true;
    }
    else
        return false;
}*/

bool check_opened_brckts(const char* string){
    char opened[] = "{[(";
    char closed[] = "}})";
    int balance = 0;
    for ( int i = 0 ; i < strlen(string) ; i++ ){
        for ( int j = 0 ; j < strlen(opened) ; j++ ){
            if ( string[i] == opened[j] )
                o_brackets.push( string[i] );
                balance++;
            else{
                if (search_c_for_o(o_brackets.top() , closed[j] )){
                    o_brackets.pop();
                    balance--;
                }
            }
        }
    }
    if ( balance == 0 and (o_brackets.empty()) )
        return true;
    else
        return false;
}

bool search_c_for_o( char opened , char closed ){
    int balance = 0;
    char opened[] = "{[(";
    char closed[] = "}})";
    for ( int i = 0 ; i < strlen(closed) ; i++ ){
        if ( (opened == opened[i]) and (closed == closed[i]) )
            balance++;
    }
    if ( balance != 0 )
        return true;
    else
        return false;
}

/*bool view(const char* string){
    for(int i=0 ; i<strlen(string) ; i++){
        if (search_brckts(string[i]))
            for (int j = 0 ; j<strlen(opened) ; j++){

            }
        else if (search_brckts(string[i])){
            if(check(brackets.top(), string[i]))
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return true;
}*/

int main(){
    std::string string;
    std::getline(std::cin, string);

    if ( !search_brckts(string.c_str()) )
         std :: cout << "True" << std :: endl;
    else if ( check_closed_brckts(string.c_str()) )
         std :: cout << "False" << std :: endl;
    else if ( check_opened_brckts(string.c_str()) )
         std :: cout << "-----" << std :: endl;
    else
         std :: cout << "False" << std :: endl;

    system("pause");
    return 0;
}
