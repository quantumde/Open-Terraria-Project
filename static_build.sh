
mkdir build 2> /dev/null
exec g++ Main.cpp external/libncursesw.a -o build/Main -static
