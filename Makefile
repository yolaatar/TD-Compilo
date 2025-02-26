# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11 -fsanitize=address -fno-omit-frame-pointer


# Cibles
TARGET = tp_compil

# Fichiers sources et objets
SRCS = main.cpp lexer.cpp symbole.cpp automate.cpp etat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
