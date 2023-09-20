RM := rm
CC := clang
CFLAGS := -Wall -Wextra -std=c17 -pedantic -g -lm -pthread
CPPFLAGS := -I./utils/include

BUILDDIR := build
SRCDIR := src
UTILDIR := utils

HEADERS := $(wildcard $(UTILDIR)/include/utils/*.h)
SRCS := $(wildcard $(SRCDIR)/*.c)
TARGETS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%,$(SRCS))


all: $(TARGETS)

# For running all targets
$(BUILDDIR)/%: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $<

# For isolated targets
%: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(BUILDDIR)/$@ $<

clean:
	$(RM) -rf $(BUILDDIR)/*


.PHONY: clean all
