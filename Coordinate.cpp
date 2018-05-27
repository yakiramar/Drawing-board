// #include <iostream>
// using namespace std;
#include "Coordinate.h"

Coordinate::Coordinate(int x2,int y2){
        x=x2;
        y=y2;
}
Coordinate::Coordinate(uint x2,uint y2){
        x=x2;
        y=y2;
}
ostream& operator<< (ostream& os, const Coordinate& p){
         os<<"("+to_string(p.x)+","+to_string(p.y)+")";
         return os;
}