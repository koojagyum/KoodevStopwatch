VERSION_MAJOR=0
VERSION_MINOR=0
VERSION_MICRO=0
VERSION_SONUM=$(VERSION_MAJOR)
VERSION=$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_MICRO)

CXX=g++

LDFLAGS=
LIBS=
CFLAGS=$(INC) -W -Wall -fPIC
CXXFLAGS=$(INC) -W -Wall -fPIC

SRCS=\
	KoodevStopwatch.cpp

OBJS=$(SRCS:.cpp=.o)

TARGET=libKoodevStopwatch.so

$(TARGET): $(OBJS)
	$(CXX) -shared -Wl,-soname,$@.$(VERSION_SONUM) -o $@.$(VERSION) $(OBJS) $(LIBS)
	ln -s $@.$(VERSION) $@.$(VERSION_SONUM)
	ln -s $@.$(VERSION_SONUM) $@
	mkdir -p $(BINDIR)
	mv $@.$(VERSION) $(BINDIR)
	mv $@.$(VERSION_SONUM) $(BINDIR)
	mv $@ $(BINDIR)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.c.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).* core
