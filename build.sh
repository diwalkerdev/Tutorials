cppcheck --check-config --enable=all -I /usr/include -I /usr/include/c++/10.1.0 multreturns.cpp
clang++ -std=c++20 -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -O1 multreturns.cpp -o program.exe