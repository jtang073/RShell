#../src/main.cpp

cat < single_command_tests.sh
echo "hi" && cat < multiple_command_tests.sh
echo "shouldn't be outputting exit commands" || cat < exit_command_tests.sh
cat < commented_command_tests.sh && echo "test passed"
