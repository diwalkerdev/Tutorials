FILE=temdeduction.cpp
cppcheck --check-config --enable=all -I /usr/include -I /usr/include/c++/10.1.0 ${FILE}
clang++ -std=c++20 -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -O1 ${FILE} -o program.exe