#include<iostream>
#include<exception>
#include<string>
using namespace std;
#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char c2){
    c=c2;
    
}

char IllegalCharException::theChar()const {
        return c;  
}