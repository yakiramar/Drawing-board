#include <iostream>
using namespace std;
#include "Pair.h"

Pair::Pair(int x2,int y2){
        x=x2;
        y=y2;
}

ostream& operator<< (ostream& os, const Pair& p){
         os<<"("+to_string(p.x)+","+to_string(p.y)+")";
         return os;
}