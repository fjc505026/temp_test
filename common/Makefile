
SRCPATH := ./src
INCPATH := ./inc
SRC_FILES := $(wildcard ./src/*.c)
OBJ_FILES := $(patsubst %.c,%.o,$(SRC_FILES))

DEFINES := 


TARGET= app
CFLAGS = -std='c99' -fdiagnostics-color=always -g -I$(INCPATH) 

$(TARGET):main.c  $(OBJ_FILES)
	-rm -f $@
	gcc  $(CFLAGS) -o $(TARGET) main.c $(OBJ_FILES) -lm

%.o:$(SRCPATH)%.c
	gcc -c $(CFLAGS) -o $@ $<

.PHONY:clean

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

