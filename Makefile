CXX=g++

LDFLAGS=-L.
LIBS=
CFLAGS=$(INC)
CXXFLAGS=$(INC) -Wall

SRCS=TestMain.cpp KoodevStopwatch.cpp
OBJS=$(SRCS:.cpp=.o)

TARGET=test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.c.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -Rf $(OBJS) $(TARGET) core
