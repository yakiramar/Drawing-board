#include <iostream>
using namespace std;
#include "IllegalCharException.h"
#include "Spot.h"


Spot::Spot():p(0,0),c('.'){
    
}

Spot::Spot(int x2,int y2,char c2):p(x2,y2),c(c2){
    
}

Spot& Spot::operator=(const Spot& s){
  p=s.p;
  c=s.c;
  return *this;
}

Spot& Spot::operator=(char c2){
  if((c2!='X')&&(c2!='O')&&(c2!='.')){throw IllegalCharException(c2);}
  c=c2;
}

ostream& operator<< (ostream& os, const Spot& s){
    os<<s.c;
    return os;
}
bool Spot::operator==(const Spot &s1) const{
  return (c==s1.c);
}
bool Spot::operator!=(const Spot &s1) const{
  return (c!=s1.c);
}
bool Spot::operator==(char ch) const{
  return(c==ch);
}
bool Spot::operator!=(char ch) const{
  return(c!=ch);
}

// char Spot::operator=(const Spot& s){
//   return s.c;
  
// }
