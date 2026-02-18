CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -pedantic -O2
SRC = main.cc
TARGET = maruBatsu

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
