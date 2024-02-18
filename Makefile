TARGET = snake

CFLAGS= -Wall -Wextra -pedantic -std=c11 
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

$(TARGET):
	$(CC) $(CFLAGS) -o app/$(TARGET) src/main.c $(LIBS)

clean:
	rm app/$(TARGET)