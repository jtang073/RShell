#!/bin/sh

echo Adding TempFile && mkdir TempFile || mkdir FakeFile; ls
echo Passed || echo Fail && echo No || echo All; echo Test


