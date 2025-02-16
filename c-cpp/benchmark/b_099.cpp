#include <benchmark/benchmark.h>

static void BM_read_file(benchmark::State &state) {
    for (auto _ : state) {
    }
}
// Register the function as a benchmark
BENCHMARK(BM_read_file)->Threads(6);

// Define another benchmark
static void BM_StringCopy(benchmark::State &state) {
    std::string x = "hello";
    for (auto _ : state)
        std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();
