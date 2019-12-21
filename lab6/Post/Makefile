# fr2md , Farid Rajabi Nia ,
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -O2 -g
.SUFFIXES: .o .cpp


OFILES = wordPuzzle.o timer.o hashTable.o 
    
wordPuzzle: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	
wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
	
hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
	
clean:
	-rm *.o wordPuzzle

timer.o: timer.cpp timer.h
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o:  wordPuzzle.cpp timer.cpp timer.h hashTable.cpp hashTable.h
