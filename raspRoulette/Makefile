EXEC=rou
OBJS=main.o LED.o
LDLIBS=-lwiringPi
CC=g++

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

clean:
	-rm -f $(EXEC) $(OBJS) *~
