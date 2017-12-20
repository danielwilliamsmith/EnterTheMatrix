set -x
make coverage
./EnterTheMatrix_Test.exe --gtest_output=xml:output.xml
mkdir cov_analysis
gcovr ./ -r /c/msys64/var/jenkins/workspace/EnterTheMatrix/src --gcov-exclude='.*_Test.*' -x -o cov_analysis/coverage.xml