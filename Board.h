#include <iostream>
#include <string>
#include <exception>
using namespace std;
#include "Spot.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"


class Board{
    private:
       uint length;
       Spot **b;
    
    public:
       Board();
       Board(uint length);
       Board(const Board& b2);
       Spot& operator[](Pair p2)const;
       Board& operator=(char in);
       Board& operator=(const Board& b2);
       bool operator==(const Board &b2) const;
    
       friend ostream& operator<< (ostream& os, const Board& b);//output
       ~Board(); 
       // Spot operator[](Pair p2)const;
       //   char operator[](Pair p2)const;
       // char operator=(const Spot& s2);
       //friend istream& operator>> (istream& input,  Board& b);  // (cin)
    
};


    
    
