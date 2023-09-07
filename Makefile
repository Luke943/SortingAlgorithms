# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -O2

# Directories
TESTDIR = tests
BUILDDIR = build

# Source files
SRC = sorting.c
OBJ = $(BUILDDIR)/sorting.o

# Test files
TESTSRC = $(wildcard $(TESTDIR)/*.c)
TESTS = $(patsubst $(TESTDIR)/%.c, $(BUILDDIR)/%, $(TESTSRC))

# Targets
all: $(BUILDDIR) $(OBJ) $(TESTS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%: $(TESTDIR)/%.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
