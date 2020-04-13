CC = gcc
CFlags = -W -Wall
TARGET = manager
DTARGET = manager_debug
OBJECTS = market.c manager.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFlags) $^ -o $@	
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFlags) -DDEBUG  $^ -o $@

clean :
	rm *.o $(TARGET) $(DTARGET)
