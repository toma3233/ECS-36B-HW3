(CXXFLAGS)=-Wall
(CXX)=g++

all: makeSVG

makeSVG: makeSVG.o
	$(CXX) -o $@ $^

clean:
	rm -f makeSVG *.o
