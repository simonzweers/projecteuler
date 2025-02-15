#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <vector>

typedef struct {
    uint64_t base;
    uint64_t exponent;
} pair_t;

int main() {
    std::ifstream f("./res/base_exp.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;
    std::vector<pair_t> pairs;
    while(std::getline(f, s)) {
        std::string t;
        std::stringstream ss{s};
        pair_t pair_tmp;

        std::getline(ss, t, ',');
        pair_tmp.base = std::stoul(t);
        std::getline(ss, t, ',');
        pair_tmp.exponent = std::stoul(t);

        std::printf("b: %ld, e: %ld\n", pair_tmp.base, pair_tmp.exponent);
    }

    

    f.close();
    return 0;
}