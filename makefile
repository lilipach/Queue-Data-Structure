TARGET = store
LIBS = -lm #Math Library, just a placeholder
HEADERS = Queue.h QueueLinked.h config.h
OBJECTS = storesim.o Queue.h QueueLinked.h
CXX = g++
CXX_FLAGS = -Wall -std=c++11 #C++11 just for reference, not necessary

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
