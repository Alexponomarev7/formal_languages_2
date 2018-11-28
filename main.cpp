#include <iostream>
#include "library.h"
#include <cassert>

int main() {
    std::vector<char> N = {'U', 'S', 'C', 'D'};
    std::vector<char> sigma = {'a', 'b', 'c'};
    std::vector<lib::Rule> P = {
                                {'U', "S"},
                                {'S', "C"},
                                {'D', "aDb"},
                                {'S', "SC"},
                                {'C', "cD"},
                                {'D', ""},
                                };
    char S = 'U';

    lib::Grammar grammar = lib::Grammar(N, sigma, P, S);

    std::string sample_in = "caaabbbcabcabcc";

    bool early_result = lib::Early(grammar).Check(sample_in);
    assert(early_result);
    std::cout << "YES" << std::endl;

    return 0;
}