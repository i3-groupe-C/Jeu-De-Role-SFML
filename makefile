CXX = g++
CXXFLAGS = -std=c++11 -g
SRC = main.cpp Game.cpp Player.cpp Tile.cpp stdafx.cpp TileMap.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC) -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)