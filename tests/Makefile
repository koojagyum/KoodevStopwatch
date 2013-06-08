TOPDIR=..
BINDIR=$(TOPDIR)\$(BINDIR_NAME)
SRCDIR=$(TOPDIR)\$(SRCDIR_NAME)

INCLUDE=$(SRCDIR)

CXX=g++

LDFLAGS=
LIBS=-L$(BINDIR) -lKoodevStopwatch
CFLAGS=$(INC) -W -Wall -I$(INCLUDE)
CXXFLAGS=$(INC) -W -Wall -I$(INCLUDE)

SRCS=\
	TestMain.cpp

OBJS=$(SRCS:.cpp=.o)

TARGET=test

$(TARGET): $(OBJS) $(BINDIR)
	$(CXX) -o $(BINDIR)\$@ $(OBJS) $(LIBS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.c.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BINDIR):
	mkdir $(BINDIR)

clean:
	$(RM) $(OBJS) $(TARGET) $(TARGET).* core
