#include <chrono>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;

typedef struct {
    uint64_t base;
    uint64_t exponent;
    double logexp;
} base_exp_t;

double get_log(base_exp_t &p) {
    return (double)p.exponent * log10((double)p.base);
}

int main() {
    std::ifstream f("./res/base_exp.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;
    std::vector<base_exp_t> pairs;
    while (std::getline(f, s)) {
        std::string t;
        std::stringstream ss{s};
        base_exp_t pair_tmp;

        std::getline(ss, t, ',');
        pair_tmp.base = std::stoul(t);
        std::getline(ss, t, ',');
        pair_tmp.exponent = std::stoul(t);

        pairs.push_back(pair_tmp);
        // std::printf("b: %ld, e: %ld\n", pair_tmp.base, pair_tmp.exponent);
    }

    uint32_t num_threads = std::thread::hardware_concurrency();
    std::printf("Number of threads: %d\n", num_threads);

    auto t1 = high_resolution_clock::now();

    double highest = 0;
    int linei = 1;
    int line;
    for (auto &pair : pairs) {
        double res = get_log(pair);
        // std::printf("b: %ld, e: %ld, log %f\n", pair.base, pair.exponent,
        // res);
        if (res > highest) {
            highest = res;
            line = linei;
        }
        linei++;
    }

    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<nanoseconds>(t2 - t1);

    std::printf("Line with highest result: %d\n", line);
    std::printf("duration %lfms\n", ((double)ms_int.count()) * (pow(10, -6)));
    f.close();
    return 0;
}