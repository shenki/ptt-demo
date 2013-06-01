# Makefile
# Joel Stanely <joel@jms.id.au>

SRC := ptt.c
OBJ := $(SRC:.c=.o)

CFLAGS += -Wall

PROG := ptt

all: $(PROG)

$(PROG): $(OBJ)
	$(LINK.c) -o $(@) $^
