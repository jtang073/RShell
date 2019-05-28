#!/bin/sh

[ -e test_symbolic_tests.sh ] && echo "test passed"
[ -f test_literal_tests.sh ] || echo "test failed"
[ -d ThisShouldFail ] || echo "test passed"
[ -e failingthistoo ] && echo "test failed" || echo "ALL TEST PASSED"

../src/main.cpp
