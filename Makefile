CC = g++
SRC = main.cpp objects.cpp shape.cpp
TARGET = shape_calculator
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)
gen:
	$(CC) generator.cpp -o generator
clean:
	rm -f $(TARGET) generator