set -x

make performance

path_root='perf_analysis/MatrixPerfTest' 
mkdir -p $path_root

path_all_csv=$path_root'/all_csv'
mkdir $path_all_csv

CodeXLCpuProfiler.exe collect -m tbp -o $path_root/BigMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BigMultiply
CodeXLCpuProfiler.exe report -i $path_root/BigMultiply.prd -I -o $path_root
cp $path_root/BigMultiply/BigMultiply.csv $path_all_csv

CodeXLCpuProfiler.exe collect -m tbp -o $path_root/BiggerMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BiggerMultiply
CodeXLCpuProfiler.exe report -i $path_root/BiggerMultiply.prd -I -o $path_root
cp $path_root/BiggerMultiply/BiggerMultiply.csv $path_all_csv

CodeXLCpuProfiler.exe collect -m tbp -o $path_root/BiggestMultiply EnterTheMatrix_Perf_Test.exe --gtest_filter=MatrixPerfTest.BiggestMultiply
CodeXLCpuProfiler.exe report -i $path_root/BiggestMultiply.prd -I -o $path_root
cp $path_root/BiggestMultiply/BiggestMultiply.csv $path_all_csv

python3 /c/Development/CPP/CsvMaker/src/CodeXlCpuProfilerExtractor.py -i $path_all_csv -o $path_all_csv/duration.csv