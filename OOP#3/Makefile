TARGET = main


HEADER_DIR = Header
SOURCE_DIR = Source


SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


CC = g++
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra


all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^


$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


run: $(TARGET)
	./$(TARGET)


clean:
	del /Q $(subst /,\,$(SOURCE_DIR)\*.o) $(TARGET).exe


.PHONY: all clean
