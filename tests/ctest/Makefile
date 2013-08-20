INCLUDE=$(SRCDIR)

LDFLAGS=
LIBS=-L$(BINDIR) -lKoodevStopwatch -lstdc++
CFLAGS=$(INC) -W -Wall -I$(INCLUDE)

SRCS=\
	TestMain.c

OBJS=$(SRCS:.c=.o)
TEST-RUNNER=$(BINDIR)/test-runner-c.sh

TARGET=test-c

$(TARGET): $(OBJS) $(TEST-RUNNER)
	$(CC) -o $@ $(OBJS) $(LIBS)
	mkdir -p $(BINDIR)
	mv $(TARGET) $(BINDIR)

$(TEST-RUNNER):
	mkdir -p $(BINDIR)
	@echo "#!/bin/sh" > $(TEST-RUNNER)
	@echo "LD_LIBRARY_PATH=$(BINDIR) $(BINDIR)/$(TARGET)" >> $(TEST-RUNNER)
	chmod +x $(TEST-RUNNER)

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).* core