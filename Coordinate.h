 #pragma once
 #include <iostream>
using namespace std;
class Coordinate{
    
    public:
        int x;
        int y;
    
        Coordinate(int x2,int y2);
        Coordinate(uint x2,uint y2);
        friend ostream& operator<< (ostream& os, const Coordinate& p);
};

