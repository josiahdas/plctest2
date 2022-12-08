#include <iterator>
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <map>

using namespace std;

int main(){

    string str = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16";

    // define list of patterns
    map<string,string> patterns {
        
        { "([-]?(?=[.]?[0-9])[0-9]*(?![.]{2})[.]?[0-9]*)" ,   "NUMERIC" },
        
        { "\\#.*" ,   "COMMENT" },
        
        { "[\\n\\r]" ,   "LINE BREAK" },
        
        { "[\\s\\t]" ,   "WHITE SPACE" },
        
        { "(incase|eincase|else|then|end|print|fun|return|when|small|large|numer|LOOP|)(?=\\s|$)" ,   "KEYWORD" },
        
        { "(\\[|\\]|\\,|\\{|}|[.]{2})" ,   "GROUP DIVIDER" },
         
        { "(true|false)(?=\\s|$)" ,   "LOGICAL" },
        
        { "(null)(?=,|\\s|$)" ,   "NULL" },
        
        { "\"([^\"]*)\"" ,   "TEXT" },
        
        { "[a-zA-Z_]+[a-zA-Z]{6,9}*" ,   "VARIABLENAME" },
        
       
        { "([+]|[-]|[*]|[/]{1,2}|[%]|>=|>|<=|[<]{1,2}|[=]{1,2}|!=|[!]|[:]{2}|[(]|[)]|(new|and|or)(?=\\s|$))",  "OPERATOR" }
        
    };

  

    // storage for results
    map< size_t, pair<string,string> > matches;

    for ( auto pat = patterns.begin(); pat != patterns.end(); ++pat )
    {
        regex r(pat->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pat->second );
    }

    for ( auto match = matches.begin(); match != matches.end(); ++match )
        cout<< match->second.first << " " << match->second.second << endl;
}
