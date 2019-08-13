#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

const char opened[] = "{[(";
const char closed[] = "}})";

bool isPair( char open_br , char close_br )
{
    for ( size_t i = 0 ; i < strlen(closed) ; ++i )
        if ( (open_br == opened[i]) and (close_br == closed[i]) )
            return true;

    return false;
}

bool searchCharInString (std::string const& string, char x )
{
    for (auto i : string)
        if (i == x)
            return true;

    return false;
}

bool search_on_string( std::string const& string )
{
    std::stack <char> o_brackets;

    for(auto i : string)
    {
        if (searchCharInString(closed, i))
        {
            if (o_brackets.empty() or !isPair(o_brackets.top(), i))
                return false;

            o_brackets.pop();
        }
        else if (searchCharInString(opened, i))
            o_brackets.push(i);
    }

    return o_brackets.empty();
}

int main()
{
    std::string string;
    std::getline(std::cin, string);

    std::cout << search_on_string(string) << std::endl;

    return 0;
}
