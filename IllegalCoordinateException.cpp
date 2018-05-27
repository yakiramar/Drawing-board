// #include <iostream>
// using namespace std;
// #include<string>
// #include <exception>
#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(int x2,int y2){
    x=x2;
    y=y2;
}
string IllegalCoordinateException::theCoordinate()const{
    return to_string(x)+","+to_string(y);
}
