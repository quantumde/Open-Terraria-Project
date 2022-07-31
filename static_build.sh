
mkdir build 2> /dev/null
exec g++ Main.cpp external/libncursesw.a -lpthread -o build/Main 
