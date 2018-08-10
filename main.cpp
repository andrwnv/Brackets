#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>


const char opened[] = "{[(";
const char closed[] = "}})";

bool search_c_for_o( char Opened , char Closed )
{
    for ( size_t i = 0 ; i < strlen(closed) ; ++i ){
        if ( (Opened == opened[i]) and (Closed == closed[i]) )
            return true;
    }
    return false;
}

bool brckts (const char arrp[], char x )
{
    for ( size_t i = 0 ; i < strlen(arrp) ; ++i )
    {
        if ( arrp[i] == x )
        {
            return true;
        }
    }
    return false;
}

bool search_on_string( const char* string )
{
    std :: stack <char> o_brackets;

    for ( size_t i = 0 ; i < strlen(string) ; ++i )
    {
        if ( brckts(closed, string[i]) )
        {
            if ( o_brackets.empty()  or (not search_c_for_o( o_brackets.top() , string[i] )))
            {
                return false;
            }
            else
            {
                o_brackets.pop();
            }
        }
        else if ( brckts(opened, string[i]) )
        {
            o_brackets.push(string[i]);
        }
    }
    return o_brackets.empty();
}

int main(){
    std::string string;
    std::getline(std::cin, string);

    if ( search_on_string(string.c_str()) )
        std :: cout << true << std :: endl;
    else{
        std :: cout << false << std :: endl;
    }
    system("pause");
    return 0;
}
