pkg-config ncurses
test "x$?" != "x0" && echo "error: ncurses not found" && exit
mkdir build 2> /dev/null
g++ Main.cpp external/libncursesw.a -o build/Main
