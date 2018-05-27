
#include "Board.h"

Board::Board(){
 length=0;
 b = new Spot*[length];
 
    for(int i = 0; i < length; i++){
        b[i] = new Spot[length]; //On heap
    }
        

}
// uint Board::size(){
//     uint a=this->length;
//     return a;
// }
Board::Board(uint length2){
length=length2;
 b = new Spot*[length];
 
    for(int i = 0; i < length; i++){
        b[i] = new Spot[length]; //On heap
    }
        
}

Board::Board(const Board& b2){
    length=b2.length;
    b=new Spot*[length];
    for(int i=0;i<length;i++)
    b[i]=new Spot[length];
    for(int i=0;i<length;i++)
    for(int j=0;j<length;j++){
        // b[i][j].c='*';
        char c2=b2.b[i][j].c;
        Spot t(i,j,c2);
        b[i][j]=t;
       
        
    }  
}

Spot& Board::operator[](Coordinate p2) const{
     if((p2.x>=length)||(p2.y>=length)){throw IllegalCoordinateException(p2.x,p2.y);}
    return b[p2.x][p2.y];
}

Board& Board::operator=(char in){
    if((in!='.')&&(in!='X')&&(in!='O')){throw IllegalCharException(in);}
    for(int i=0;i<length;i++)
    for(int j=0;j<length;j++){
        Spot t(i,j,in);
        b[i][j]=t;
       
        
    } 
 return *this;
}

Board& Board::operator=(const Board& b2){
    if(this==&b2){
        return *this;
        
    }
    
    for(int i=0; i<length; i++){
        delete[] b[i];
    } 
    
    delete[]b;
    length=b2.length;
    b=new Spot*[length];
    
    for(int i=0;i<length;i++){
        b[i]=new Spot[length];
        for(int j=0;j<length;j++){
            char c2=b2.b[i][j].c;
            Spot t(i,j,c2);
            b[i][j]=t;
        }  
    }
    return *this;
 }



ostream& operator<< (ostream& os, const Board& temp_b){
    for(int i=0;i<temp_b.length;i++){
        for(int j=0;j<temp_b.length;j++){
            os<<temp_b.b[i][j].c;
        }
        os<<endl;
    }
    return os;
    
}
    
Board::~Board(){
    for (int i = 0; i < length; i++){
         delete[] b[i];
    }
    delete[] b;
        
}
 bool Board::operator==(const Board &b2) const{
        if(length!=b2.length){return false;}
        for(int i=0;i<length;i++){
         for(int j=0;j<length;j++){
             if(b[i][j]!=b2.b[i][j]){return false;}
         }
        }
        return true;
    }


// char Board::operator[](Coordinate p2)const{
//     if((p2.x>=length)||(p2.y>=length)){throw IllegalCoordinateException(p2.x,p2.y);}
//     return b[p2.x][p2.y].c;
// }

// Spot Board::operator[](Coordinate p2)const{
//     if((p2.x>=length)||(p2.y>=length)){throw IllegalCoordinateException(p2.x,p2.y);}
//     return b[p2.x][p2.y];
// }

//  char Board::operator=(const Spot& s2){
//      return s2.c;
//  }
