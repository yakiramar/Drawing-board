#include<iostream>
#include<exception>
#include<string>
using namespace std;

class IllegalCharException:public exception{
    public:
      char c;
      IllegalCharException(char c);
      char theChar()const;
};