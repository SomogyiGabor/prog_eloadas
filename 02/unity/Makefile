UNITY_HOME = $(HOME)/Unity/src

TARGET = sprintf_test
SOURCES = \
	SprintfTest.c \
	SprintfTestRunner.c \
	AllTests.c

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

CFLAGS += -I$(UNITY_HOME)

CC = gcc
LD = gcc
CPP = gcc -E

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@  $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	$(CPP) $(CFLAGS) -MM -MP -MG -MF $*.d $<

-include $(DEPS)

.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(TARGET)
