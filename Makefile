SRC = ./src/Main.cpp
CPP = /usr/bin/c++
CFLAGS = "-lncurses" "-lpthread"
all::
	@$(CPP) $(SRC) $(CFLAGS) -o ost
install::
	@cp ./ost /usr/bin/ost