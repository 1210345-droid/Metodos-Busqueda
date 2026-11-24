CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2
TARGET = prueba-busqueda
SOURCES = test.c metodosBusqueda.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCES) metodosBusqueda.h
	$(CC) $(CFLAGS) $(SOURCES) -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
