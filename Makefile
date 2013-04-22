DIRS=src tests

TOPDIR:=$(shell pwd)
export BINDIR=$(TOPDIR)/bin
export SRCDIR=$(TOPDIR)/src

all:
	@for dir in $(DIRS); do \
	make -C $$dir || exit $?; \
	done

clean:
	@for dir in $(DIRS); do \
	make -C $$dir clean; \
	done
	rm -rf $(BINDIR)