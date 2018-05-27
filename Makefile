CCX=g++ -std=c++11





a.out: Board.o Pair.o Spot.o IllegalCoordinateException.o IllegalCharException.o 

		

		

Board.o: Board.cpp Board.h

		$(CCX) -c Board.cpp

		

Pair.o: Pair.cpp Pair.h

		$(CCX) -c Pair.cpp

		

Spot.o: Spot.cpp Spot.h

		$(CCX) -c Spot.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h

		$(CCX) -c IllegalCoordinateException.cpp
		
		
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h

		$(CCX) -c IllegalCharException.cpp

		

Clean:

		rm *.o a.out
