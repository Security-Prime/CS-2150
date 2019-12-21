# fr2md , Farid Rajabi Nia ,

CXX= clang++ $(CXXFLAGS)
CXX1= clang++ -o encoder
CXX2= clang++ -o decoder
DEBUG= -Wall -O2 -g
.SUFFIXES: .o .cpp


OFILES = heap.o huffNode.o huffTree.o huffmanenc.o

main: huffmanenc huffmandec
    
huffmanenc: $(OFILES)
	$(CXX1) $(DEBUG) $(OFILES)
	
huffmanenc.o: huffmanenc.cpp
	$(CXX) -c huffmanenc.cpp

huffTree.o: huffTree.cpp huffTree.h
	$(CXX) -c huffTree.cpp
	
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp

heap.o: heap.cpp heap.h
	$(CXX) -c heap.cpp


OFILE = huffNode.o treeBuilder.o huffmandec.o
    
huffmandec: $(OFILE)
	$(CXX2) $(DEBUG) $(OFILE)
	
huffmandec.o: huffmandec.cpp
	$(CXX) -c huffmandec.cpp

treeBuilder.o: treeBuilder.cpp treeBuilder.h
	$(CXX) -c treeBuilder.cpp
	
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp


clean:
	-rm *.o huffmanenc
	-rm *.o huffmandec


heap.o: heap.cpp heap.h
huffTree.o: huffTree.cpp huffTree.h
huffNode.o: huffNode.cpp huffNode.h
huffmanenc.o: huffmanenc.cpp heap.cpp heap.h huffTree.cpp huffTree.h huffNode.cpp huffNode.h

treeBuilder.o: treeBuilder.cpp treeBuilder.h
huffNode.o: huffNode.cpp huffNode.h
huffmandec.o: huffmandec.cpp treeBuilder.cpp treeBuilder.h huffNode.cpp huffNode.h

