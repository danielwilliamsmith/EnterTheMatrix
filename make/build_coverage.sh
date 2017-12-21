set -x
make coverage
./EnterTheMatrix_Test.exe --gtest_output=xml:output.xml
mkdir cov_analysis
mkdir cov_analysis/gcov
mkdir cov_analysis/lcov
gcovr ./ -r /c/msys64/var/jenkins/workspace/EnterTheMatrix/src --gcov-exclude='.*_Test.*' -x -o cov_analysis/gcov/coverage.xml
lcov -c -d ./ -d /c/msys64/var/jenkins/workspace/EnterTheMatrix/src --no-external --rc lcov_branch_coverage=1 -o cov_analysis/lcov/coverage.info
genhtml cov_analysis/lcov/coverage.info --rc genhtml_branch_coverage=1 -o cov_analysis/lcov/coverage_html