TOPDIR=..
BINDIR=$(TOPDIR)\$(BINDIR_NAME)

CXX=g++

LDFLAGS=
LIBS=
CFLAGS=$(INC) -W -Wall -fPIC
CXXFLAGS=$(INC) -W -Wall -fPIC

SRCS=\
	KoodevStopwatch.cpp

OBJS=$(SRCS:.cpp=.o)

TARGET=libKoodevStopwatch.dll

$(TARGET): $(OBJS) $(BINDIR)
	$(CXX) -shared -Wl,-soname,$@ -o $(BINDIR)\$@ $(OBJS) $(LIBS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.c.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BINDIR):
	mkdir $(BINDIR)

clean:
	$(RM) $(OBJS) $(TARGET) $(TARGET).* core
