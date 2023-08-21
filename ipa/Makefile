CCC = g++
CCFLAGS = -Werror -pedantic -Wall -Wextra -Wvla -std=c++17
SRC = *.cpp
INC = ../include

ifeq ($(OS),Windows_NT)
	# Windows
	LIB = -lglu32 -lfreeglut -lopengl32
else
	# Others
	OS := $(shell uname)
	ifeq ($(OS),Linux)
		# Linux
		LIB = -lglut -lGL -lGLU
	endif
	ifeq ($(OS),Darwin)
		# Mac
		LIB = -framework OpenGL -framework GLUT
	endif
endif

.PHONY: all clean

all: ipa

ipa:
	$(CCC) $(CCFLAGS) -o ipa -I $(INC) $(SRC) $(LIB)

ipa-asan:
	clang++ -DDEBUG -DNO_GUI -g -fsanitize=address,leak,undefined,integer,bounds,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-sanitize-recover=all -o ipa-asan -I $(INC) $(SRC)

clean:
	$(RM) *.o *.a *~ ipa ipa-asan
