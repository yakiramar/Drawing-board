#include <iostream>
using namespace std;
class Pair{
    
    public:
        int x;
        int y;
    
        Pair(int x2,int y2);
        friend ostream& operator<< (ostream& os, const Pair& p);
};

