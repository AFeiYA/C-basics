#include <iostream>
#include <regex>
#include <iterator>
using namespace std;



int main()
{
    string regSrc = "  11       TPPL  5655  123   100  0  ";
    //string regSrc = "  11  2   5655.120  -123.456    100.002  ";

    cout<<regSrc<<endl;
    //regex  self_reg("REGULAR_EXPRESSIONS", regex_constants::ECMAScript|regex_constants::icase);

    regex word_regex("([-|\\d]+\\.+\\d+)|(\\d+)");
    regex face_regex("(\\w+)");

    auto words_begin = sregex_iterator(regSrc.begin(),regSrc.end(),face_regex);
    auto words_end = sregex_iterator();
    for(sregex_iterator i=words_begin; i!=words_end;++i){
        std::smatch match = *i;
        string match_str =  match.str();
        cout<<match_str.length()<<endl;
    }

    return 0;
    
}