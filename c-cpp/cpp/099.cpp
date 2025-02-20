#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>
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

uint32_t solution_part(
		std::vector<base_exp_t> &pairs,
		uint32_t begin,
		uint32_t end
		) {
	
    double highest = 0;
    int line = 0;
    for (uint32_t i = begin; i < end; ++i) {
        double res = get_log(pairs[i]);
        // std::printf("b: %ld, e: %ld, log %f\n", pair.base, pair.exponent,
        // res);
        if (res > highest) {
            highest = res;
            line = i;
        }
    }
	return line;
}

uint32_t euler99_st(std::vector<base_exp_t> &pairs) {

    double highest = 0;
    int linei = 1;
    int line = 0;

    for (uint32_t i = 0; i < pairs.size(); ++i) {
        double res = get_log(pairs[i]);
        // std::printf("b: %ld, e: %ld, log %f\n", pair.base, pair.exponent,
        // res);
        if (res > highest) {
            highest = res;
            line = linei;
        }
        linei++;
    }

	return line;
}

uint32_t euler99_mt(std::vector<base_exp_t> &pairs) {

    double highest = 0;
    int linei = 1;
    int line = 0;
	uint32_t left = 0;
	uint32_t middle = pairs.size() / 2;
	uint32_t end = pairs.size();
	
	uint32_t leftMax = solution_part(
			pairs,
			left,
			middle
	);
	uint32_t rightMax = solution_part(
			pairs,
			middle,
			end
	);
	line = leftMax;
	if ( rightMax > leftMax)
		line = rightMax;
    return line + 1;
}

int read_file(std::vector<base_exp_t> &pairs) {
    std::ifstream f("./res/base_exp.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;
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
    f.close();
    return 0;
}

int main() {

    uint32_t num_threads = std::thread::hardware_concurrency();
    std::printf("Number of threads: %d\n", num_threads);
    std::vector<base_exp_t> pairs;
    read_file(pairs);
    auto t1 = high_resolution_clock::now();
    uint32_t line = euler99_st(pairs);
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<nanoseconds>(t2 - t1);

    std::printf("Line with highest result: %d\n", line);
    std::printf("duration %lfms\n", ((double)ms_int.count()) * (pow(10, -6)));
    return 0;
}
