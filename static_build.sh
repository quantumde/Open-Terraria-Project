
mkdir build 2> /dev/null
exec g++ Main.cpp external/lib{ncursesw,pthread}.a -o build/Main -static
