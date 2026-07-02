CC = gcc
# 加上 -mconsole，强制编译为控制台程序
CFLAGS = -Wall -g -mconsole
TARGET = score_system
SRCS = main.c student.c file_utils.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o