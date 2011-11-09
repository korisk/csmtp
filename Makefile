CXX=g++
CXXFLAGS=-c -Wall -ggdb -DPURIFY
LDFLAGS= -lssl
SOURCES=base64.cpp CSmtp.cpp main.cpp md5.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=smtptest

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@
	ctags -R ./*

clean:
	rm --verbose ./*.o ./$(EXECUTABLE) ./tags


