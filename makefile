# target: prereuistes
# 	recipe


CC = g++
TARGET = main
SOURCE = main.cpp

$(TARGET): $(SOURCE)
	$(CC) -o $@ $<

clean:
	rm $(TARGET)
