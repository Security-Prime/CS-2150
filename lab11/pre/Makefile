# fr2md , Farid Rajabi Nia 

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -O2 -g
.SUFFIXES: .o .cpp


OFILES = topological.o 
    
topological: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	doxygen
	
	
clean:
	-rm *.o topological

