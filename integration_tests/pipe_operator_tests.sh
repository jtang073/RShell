#../src/main.cpp

cat < exit_command_tests.sh | tr a-z A-Z | tee newExitCommandFile.txt && echo "Testing piping operator"
cat < test_literal_tests.sh | tr a-z A-Z > newTestLiteralFile.txt && echo "Made 2 new files"
cat < test_symbolic_tests.sh | tr a-z A-Z > newTestLiteralFile.txt && echo "changed literals to symbolic"
