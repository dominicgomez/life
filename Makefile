SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .h .c .o .d

srcdir = ./src
objdir = ./obj
depdir = ./.dep
bindir = ./bin

srcs = $(wildcard $(srcdir)/*.c)
objs = $(subst $(srcdir), $(objdir), $(patsubst %.c, %.o, $(srcs)))
deps = $(subst $(objdir), $(depdir), $(patsubst %.o, %.d, $(objs)))
bin = $(bindir)/life

CC = gcc
CFLAGS = -c -MMD -MF$(depdir)/$*.d -I$(srcdir) -x c -Wall -Wextra -std=c11
LDFLAGS = -lncurses

$(bin): $(objs)
	$(CC) $(LDFLAGS) $^ -o $@

$(objdir)/%.o: $(srcdir)/%.c | .dep
	$(CC) $(CFLAGS) $< -o $@

.dep:
	mkdir -p $@

-include $(depdir)/*.d

.PHONY: clean
clean:
	rm -rf $(objs) $(depdir) $(bin)
