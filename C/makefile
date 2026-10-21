# target: prereuistes
# 	recipe


CC = gcc
TARGET = main
SOURCE = main.c


$(TARGET): $(SOURCE)
	$(CC) -o $@ $<

test: test.c
	$(CC) -o $@ $<


clean:
	rm $(TARGET)
