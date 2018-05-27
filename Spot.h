#include <iostream>
using namespace std;
#include "Pair.h"

class Spot{
       
    public:
       Pair p;
       char c;
       Spot();
       Spot(int x2,int y2,char c2);
       Spot& operator=(const Spot& s);
       Spot& operator=(char c2);
       operator char(){return c;}
       bool operator==(const Spot &c1) const;
       bool operator!=(const Spot &c1) const;
       bool operator==(char ch) const;
       bool operator!=(char ch) const;
       friend ostream& operator<< (ostream& os, const Spot& s);
      // char operator=(const Spot& s);
       //   Spot& operator[](Pair p_in);
};

