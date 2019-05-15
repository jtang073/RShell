#!/bin/sh
#!/bin/../header/main.cpp
echo Welcome; echo "to our rshell" && echo "integration" && echo test
echo Adding TempFile && mkdir TempFile || mkdir FakeFile; ls && rm -r TempFile
echo Passed || echo Fail && echo All || echo No; echo Test
git status && ls || echo Test && echo "Testing" || echo "Test Passed"


../header/main
