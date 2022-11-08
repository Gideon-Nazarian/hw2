#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <vector>
 
using namespace std;
std::string convToLower(std::string src)
{
   std::transform(src.begin(), src.end(), src.begin(), ::tolower);
   return src;
}
 
/** Complete the code to convert a string containing a rawWord
   to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{ 
   
   std::set<string> keyWords;
   string input = convToLower(rawWords);
   input = ltrim(input);
   string singleWord = "";
 
   for (int i = 0; i < (int)input.size();++i){
       if(ispunct(input[i]) != 0){ // if is punct
           if( i > 0 ){
               if(isdigit(input[i-1]) != 0 ){ //isbn
                   singleWord+= input[i];
               }
               else if(singleWord.size() > 1) {
                   keyWords.insert(singleWord);
                   singleWord = "";
               }
               else{
                   singleWord = "";
               }
           }
       }
       else if(isspace(input[i]) != 0){ //if is whitespace
           if(singleWord.size() > 1) {
                   keyWords.insert(singleWord);
                   singleWord = "";
               }
 
           singleWord = "";
 
 
       }else{
           singleWord+= input[i];
       }
    }
   if(singleWord.size() > 1) {
       keyWords.insert(singleWord);
       singleWord = "";
   }
   return keyWords;
  
}

 
/**************************************************
* COMPLETED - You may use the following functions
**************************************************/
 
// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
   s.erase(s.begin(),
       std::find_if(s.begin(),
            s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
   return s;
}
 
// trim from end
std::string &rtrim(std::string &s) {
   s.erase(
       std::find_if(s.rbegin(),
            s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
       s.end());
   return s;
}
 
// trim from both ends
std::string &trim(std::string &s) {
   return ltrim(rtrim(s));
}
