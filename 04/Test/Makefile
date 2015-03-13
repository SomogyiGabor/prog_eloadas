TARGET = ledDriverTest
SOURCES = \
	LedDriverTest.cpp \
	../LedDriver.c \
	RuntimeErrorStub.c

C_SOURCES = $(filter %.c,$(SOURCES))
CXX_SOURCES = $(filter %.cpp,$(SOURCES))

OBJECTS = $(C_SOURCES:.c=.o) $(CXX_SOURCES:.cpp=.o)
DEPS = $(C_SOURCES:.c=.d) $(CXX_SOURCES:.cpp=.d)

INCLUDE_DIRECTORIES = \
	../

INCLUDE_FLAGS = $(patsubst %,-I%,$(INCLUDE_DIRECTORIES))

CFLAGS = $(INCLUDE_FLAGS)
CXXFLAGS = $(INCLUDE_FLAGS)
LDFLAGS = -lCppUTest

CC = gcc
CXX = g++
LD = g++
CPP = g++ -E

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@  $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	@$(CPP) $(CFLAGS) -MM -MP -MG -MF $*.d $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@$(CPP) $(CFLAGS) -MM -MP -MG -MF $*.d $<

-include $(DEPS)

.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(TARGET)
