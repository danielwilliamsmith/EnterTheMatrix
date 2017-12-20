set -x
make performance
mkdir perf_analysis 
CodeXLCpuProfiler.exe collect -m tbp -o perf_analysis/perf EnterTheMatrix_Perf_Test.exe
CodeXLCpuProfiler.exe report -i perf_analysis/perf.prd -I -o perf_analysis/
python3 /c/Development/CPP/CsvMaker/src/CodeXlCpuProfilerExtractor.py -i perf_analysis/perf/perf.csv -o perf_analysis/perf/duration.csv