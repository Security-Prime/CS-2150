# fr2md , Farid Rajabi Nia ,

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -O2 -g
.SUFFIXES: .o .cpp


OFILES = huffNode.o treeBuilder.o huffmandec.o
    
huffmanenc: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	
huffmanenc.o: huffmandec.cpp
	$(CXX) -c huffmandec.cpp

treeBuilder.o: treeBuilder.cpp treeBuilder.h
	$(CXX) -c treeBuilder.cpp
	
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp

clean:
	-rm *.o huffmandec

treeBuilder.o: treeBuilder.cpp treeBuilder.h
huffNode.o: huffNode.cpp huffNode.h
huffmanenc.o: huffmandec.cpp treeBuilder.cpp treeBuilder.h huffNode.cpp huffNode.h

