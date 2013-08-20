DIRS=cpptest ctest

all:
	@for dir in $(DIRS); do \
	make -C $$dir || exit $?; \
	done

clean:
	@for dir in $(DIRS); do \
	make -C $$dir clean; \
	done