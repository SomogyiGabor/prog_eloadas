TARGET = ledDriverTest
SOURCES = \
	LedDriverTest.cpp
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(SOURCES:.cpp=.d)

CXXFLAGS =
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
