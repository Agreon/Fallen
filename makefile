#Files
OBJS = *.cpp *.h $(wildcard AgreonLibrary2/*.h) $(wildcard AgreonLibrary2/*.cpp)

#Compiler
CC = g++

#Flags
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++11 -I/usr/include/freetype2

#LINKER_FLAGS 
LINKER_FLAGS = -lSDL2main -lSDL2 -lGL -lSDL2_image -lSDL2_mixer -lftgl

#Executable Name
OBJ_NAME = Fallen

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) && ./$(OBJ_NAME)