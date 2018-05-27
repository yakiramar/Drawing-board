CCX=g++ -std=c++11





a.out: Board.o Coordinate.o Spot.o IllegalCoordinateException.o IllegalCharException.o 

		

		

Board.o: Board.cpp Board.h

		$(CCX) -c Board.cpp

		

Coordinate.o: Coordinate.cpp Coordinate.h

		$(CCX) -c Coordinate.cpp

		

Spot.o: Spot.cpp Spot.h

		$(CCX) -c Spot.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h

		$(CCX) -c IllegalCoordinateException.cpp
		
		
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h

		$(CCX) -c IllegalCharException.cpp

		

Clean:

		rm *.o a.out
