 #pragma once
 #include <iostream>
using namespace std;
#include <exception>
#include<string>



class IllegalCoordinateException : public exception {
    public:
      int x;
      int y;
      IllegalCoordinateException(int x,int y);
      string theCoordinate()const;
  
};