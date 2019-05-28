#!/bin/bash
#!/bin/../src/main.cpp

test -e src && echo "SRC does exist"
echo "Testing test function" && test -d images || echo "pls work"
test -f src || echo "F stands for file not folder lol"
echo "CMakeLists.txt is a file" && test -f CMakeLists.txt


../src/main.cpp
