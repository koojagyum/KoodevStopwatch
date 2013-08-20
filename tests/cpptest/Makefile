INCLUDE=$(SRCDIR)

CXX=g++

LDFLAGS=
LIBS=-L$(BINDIR) -lKoodevStopwatch
CFLAGS=$(INC) -W -Wall -I$(INCLUDE)
CXXFLAGS=$(INC) -W -Wall -I$(INCLUDE)

SRCS=\
	TestMain.cpp

OBJS=$(SRCS:.cpp=.o)
TEST-RUNNER=$(BINDIR)/test-runner-cpp.sh

TARGET=test-cpp

$(TARGET): $(OBJS) $(TEST-RUNNER)
	$(CXX) -o $@ $(OBJS) $(LIBS)
	mkdir -p $(BINDIR)
	mv $(TARGET) $(BINDIR)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.c.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(TEST-RUNNER):
	mkdir -p $(BINDIR)
	@echo "#!/bin/sh" > $(TEST-RUNNER)
	@echo "LD_LIBRARY_PATH=$(BINDIR) $(BINDIR)/$(TARGET)" >> $(TEST-RUNNER)
	chmod +x $(TEST-RUNNER)

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).* core
