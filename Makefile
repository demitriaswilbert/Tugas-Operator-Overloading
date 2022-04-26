SOURCE = $(wildcard src/*.cpp)

CXX = g++
CXXFLAGS = --std=c++17 -O3 -Wall -Wextra -Iinclude


BUILD_DIR = build
TARGET = main


OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCE:.cpp=.o)))
vpath %.cpp $(sort $(dir $(SOURCE)))

all : $(TARGET).exe

$(BUILD_DIR) :
	mkdir $@

$(BUILD_DIR)/%.o: %.cpp $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@ 

$(TARGET).exe : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

run : $(TARGET).exe
	./$(TARGET).exe

clean : 
	rm -fR $(BUILD_DIR) *.exe

