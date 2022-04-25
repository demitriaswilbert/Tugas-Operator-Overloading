SOURCE = $(wildcard src/*.cpp)

CXX = g++
CXXFLAGS = --std=c++17 -O3 -Wall -Wextra -Iinclude

TARGET = main

BUILD_DIR = build

all : $(BUILD_DIR)/$(TARGET).exe

OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCE:.cpp=.o)))
vpath %.cpp $(sort $(dir $(SOURCE)))

$(BUILD_DIR) :
	mkdir $@

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@ 

$(BUILD_DIR)/$(TARGET).exe : $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

run : $(BUILD_DIR)/$(TARGET).exe
	./build/main.exe

clean : 
	rm -fR build

