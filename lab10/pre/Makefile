# fr2md , Farid Rajabi Nia ,

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -O2 -g
.SUFFIXES: .o .cpp


OFILES = heap.o huffNode.o huffTree.o huffmanenc.o
    
huffmanenc: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	
huffmanenc.o: huffmanenc.cpp
	$(CXX) -c huffmanenc.cpp

huffTree.o: huffTree.cpp huffTree.h
	$(CXX) -c huffTree.cpp
	
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp

heap.o: heap.cpp heap.h
	$(CXX) -c heap.cpp

	
clean:
	-rm *.o huffmanenc

heap.o: heap.cpp heap.h
huffTree.o: huffTree.cpp huffTree.h
huffNode.o: huffNode.cpp huffNode.h
huffmanenc.o: huffmanenc.cpp heap.cpp heap.h huffTree.cpp huffTree.h huffNode.cpp huffNode.h

