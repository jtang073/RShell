#!/bin/sh

(echo Testing && echo Precedence) && echo "This should work"
(ls -j && echo "This should fail") || echo "This should be echoing"
(test -e src || echo A) && echo B
(echo c && echo d) || (echo a || echo b)

../src/main.cpp
