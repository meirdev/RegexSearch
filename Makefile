CPP = g++
CXXFLAGS = -ansi -pedantic -Wall -Werror -Wconversion -std=c++0x -g
CPPFLAGS = -I.
LDFLAGS  = -lpthread

PROGRAM = XSearch

SOURCES = Main.cpp \
		  ./ThreadPool/ThreadPool.cpp \
		  ./Search/ABCSearch.cpp \
		  ./Search/SearchResult.cpp \
		  ./Search/RegularSearch/RegularSearch.cpp \
		  ./Search/RegexSearch/RegexSearch.cpp \
		  ./FileSystem/Local/LocalFile.cpp \
		  ./FileSystem/Local/LocalDirectory.cpp \
		  ./XSearch.cpp \
		  ./Runnable/FileReader.cpp \
		  ./Runnable/Search.cpp \
		  ./Style/Ack/Ack.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(PROGRAM): $(OBJECTS)
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(CPPFLAGS) $(OBJECTS) -o $(PROGRAM)

include depends

depends:
	$(CPP) $(CXXFLAGS) $(CPPFLAGS) -MM $(SOURCES) > depends

run:
	@./$(PROGRAM)

gdb:
	@gdb ./$(PROGRAM) -q

clean:
	rm depends $(PROGRAM)
	find . -name '*.o' -type f -delete