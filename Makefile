DIRS=src tests

export BINDIR_NAME=bin
export SRCDIR_NAME=src

BINDIR=$(BINDIR_NAME)

export MAKE=mingw32-make.exe
export RM=del /q
export RMDIR=rmdir /s /q
export MOVE=move

all:
	@for %%d in ($(DIRS)) do \
	$(MAKE) -C %%d || exit $?

clean:
	@for %%d in ($(DIRS)) do \
	$(MAKE) -C %%d clean
	$(RMDIR) $(BINDIR)
