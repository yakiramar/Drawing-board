
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

istream& operator>> (istream& input, Board& b_out){
    string s;
    cin>>s;
    uint l=s.length();
    Board t{l};
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            t.b[i][j].c=s[j];
        }
        cin>>s;
    }
    b_out=t;
    return input;
    
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
void Dcircle(RGB* imge,int Xfrom,int Xto,int Yfrom,int Yto,int dimy){
    int R = ((Xto - Xfrom) / 2) -(int)((Xto-5 - Xfrom+5)%10);  //redius - need to fix
				int Ox = (Xto - Xfrom) / 2 ;      // xmid
				int Oy = (Yto - Yfrom) / 2 ;      //ymid
    //  a nicer circale with the help of yossi
                for (int y=0; y<2*R; y++){
                    for (int x=0; x<2*R; x++){
                        if ( floor(sqrt( (x-Ox)*(x-Ox) + (y-Oy)*(y-Oy) ) ) == R-10 ) {
                            imge[dimy * (y + Yfrom) + Xfrom + x]={0,255,0};
                            imge[dimy * (y + Yfrom) + Xfrom + x+1]={0,255,0};
                            imge[dimy * (y + Yfrom) + Xfrom + x+2]={0,255,0};
                            imge[dimy * (y + Yfrom) + Xfrom + x-1]={0,255,0};
                        }
                    }
                }              
}
void Dex(RGB* imge,int Xfrom,int Xto,int Yfrom,int Yto,int dimy){
    //func tha draw x
    for (int r = 10; r < Yto - Yfrom - 10 ; ++r) {
					//Drawing main diagonal of X
                    imge[dimy * (r + Yfrom) + Xfrom + r]={255,0,0};
                    //make shape bigger/bold
                    imge[dimy * (r + Yfrom) + Xfrom + r-1]={255,0,0};
                    imge[dimy * (r + Yfrom) + Xfrom + r+1]={255,0,0};					
					//Drawing secondery diagonal of X
                    imge[dimy * (r + Yfrom) + Xto - (r)]={255,0,0};
                    //make shape bigger/bold
                    imge[dimy * (r + Yfrom) + Xto - (r)-1]={255,0,0};
                    imge[dimy * (r + Yfrom) + Xto - (r)+1]={255,0,0};
	}  
}

   
string Board::draw(int nPx){
    const int dimx=nPx;
    const int dimy=nPx;
    string fileName="myboard.ppm";
    ifstream file(fileName);
    bool myfileExist=false;
    if(file){
        //cout<< "i's exist!!!"<<'\n';
        myfileExist=true;
    }
    int i=1;
    while(myfileExist){  //if we have pic alredy
        fileName="MyBoard";
        fileName+=to_string(i);
        fileName+=".ppm";

        ifstream file(fileName);
        if(file){i++;}
        else{myfileExist=false;}
    }
    //create new file
    ofstream imgFile(fileName);
    imgFile<<"P6"<<'\n'<< dimx << " " << dimy << '\n' << 255 <<'\n';
    // start building the pic:   
    // create mat for pixel:   
    RGB imge[dimx*dimy];
    //background color
    for(int j=0; j<dimy;j++){  // row
       for(int i=0; i<dimx;i++){ // column               
        //    imge[(dimx*j)+i].red = (i % 256);
        //    imge[(dimx*j)+i].green = (j % 256);
        //    imge[(dimx*j)+i].blue = ( ((i*i)+(j*j)) % 256);
           imge[(dimx*j)+i]={255,255,255};           
         }
    } 
    int cellsize = dimx/length; //size for each coordinate
    //lets make speration lins
    //Drawing the cols
	for (int i = 0; i < length; ++i) {
		int Xfrom = i * (cellsize);
		for (int r = 3; r < dimy - 3 ; ++r) {
            imge[dimy * (r) + Xfrom]={0,0,0};			
		}
	}
	//Drawing the rows
	for (int j = 0; j < length; ++j) {
		int Yfrom = j * (cellsize) ;
		for (int r = 3; r < dimx - 3 ; ++r) {
            imge[(r) + Yfrom * dimy]={0,0,0};
		}
	}
	int loop = 0;
	//Drawing symbols
	for (int row = 0; row < length; ++row) {
		for (int column = 0; column < length; ++column) {
            //coordinate for moving between cells
			int Xfrom = column * (cellsize);
			int Xto = (column + 1) * (cellsize); //dont include the last bit
			int Yfrom = row * (cellsize) ;
			int Yto = (row + 1) * (cellsize); //dont include the last bit
			if (b[row][column] == 'X') {
                //Drawing X
                Dex(imge,Xfrom,Xto,Yfrom,Yto,dimy);  			
			}
			else if(b[row][column] == 'O'){
				//Drawing O
                
                //from https://github.com/GeekCSA/Exercise-8---Draw/blob/master/Board.cpp

				// int R = ((Xto - Xfrom) / 2) -(int)((Xto-5 - Xfrom+5)%10);  //redius - need to fix
				// int Ox = (Xto - Xfrom) / 2 ;      // xmid
				// int Oy = (Yto - Yfrom) / 2 ;      //ymid

				// for (int X = 10; X < Yto - Yfrom - 10 ; ++X) {
				// 	int Y = floor(sqrt(R*R - (X - Ox)*(X - Ox)) + Oy);
				// 	int attach = 20;
				// 	//Drawing bottom size of the circle
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+1]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+2]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+3]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+4]={0,0,255};
                //     //Drawing upper size of the circle ?
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+1]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+2]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+3]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+4]={0,0,255};
				// }
                //  a nicer circle with the help of yossi
                 Dcircle(imge,Xfrom,Xto,Yfrom,Yto,dimy);    
			}
		}
	}
    imgFile.write(reinterpret_cast<char*>(&imge),3*dimx*dimy);
    imgFile.close();
    return fileName;
}
