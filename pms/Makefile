CCC = g++
CCFLAGS = -Werror -pedantic -Wall -Wextra -Wvla -std=c++17
SRC = *.cpp
INC = ../include

.PHONY: all clean

all: pms

pms:
	$(CCC) $(CCFLAGS) -o pms -I $(INC) $(SRC)

pms-asan:
	clang++ -DDEBUG -DNO_GUI -g -fsanitize=address,leak,undefined,integer,bounds,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-sanitize-recover=all -o pms-asan -I $(INC) $(SRC)

clean:
	$(RM) *.o *.a *~ pms pms-asan
