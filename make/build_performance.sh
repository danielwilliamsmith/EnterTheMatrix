set -x

make performance

mkdir -p perf_analysis/MatrixPerfTest

path_BigMultiply='perf_analysis/MatrixPerfTest/BigMultiply'
path_BiggerMultiply='perf_analysis/MatrixPerfTest/BiggerMultiply'
path_BiggestMultiply='perf_analysis/MatrixPerfTest/BiggestMultiply'
mkdir $path_BigMultiply
mkdir $path_BiggerMultiply
mkdir $path_BiggestMultiply

CodeXLCpuProfiler.exe collect -m tbp -o $path_BigMultiply/perf_BigMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BigMultiply
CodeXLCpuProfiler.exe report -i $path_BigMultiply/perf_BigMultiply.prd -I -o $path_BigMultiply
python3 /c/Development/CPP/CsvMaker/src/CodeXlCpuProfilerExtractor.py -i $path_BigMultiply/perf_BigMultiply/perf_BigMultiply.csv -o $path_BigMultiply/perf_BigMultiply/duration_BigMultiply.csv

CodeXLCpuProfiler.exe collect -m tbp -o $path_BiggerMultiply/perf_BiggerMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BiggerMultiply
CodeXLCpuProfiler.exe report -i $path_BiggerMultiply/perf_BiggerMultiply.prd -I -o $path_BiggerMultiply
python3 /c/Development/CPP/CsvMaker/src/CodeXlCpuProfilerExtractor.py -i $path_BiggerMultiply/perf_BiggerMultiply/perf_BiggerMultiply.csv -o $path_BiggerMultiply/perf_BiggerMultiply/duration_BiggerMultiply.csv

CodeXLCpuProfiler.exe collect -m tbp -o $path_BiggestMultiply/perf_BiggestMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BiggestMultiply
CodeXLCpuProfiler.exe report -i $path_BiggestMultiply/perf_BiggestMultiply.prd -I -o $path_BiggestMultiply
python3 /c/Development/CPP/CsvMaker/src/CodeXlCpuProfilerExtractor.py -i $path_BiggestMultiply/perf_BiggestMultiply/perf_BiggestMultiply.csv -o $path_BiggestMultiply/perf_BiggestMultiply/duration_BiggestMultiply.csv