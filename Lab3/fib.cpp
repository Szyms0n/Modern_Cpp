#include "fib.hpp"//

#include <iostream>
#include <fstream>
#include <vector>
// Created by Szymon Hetman on 26/10/2026.
//

int fib_recurrency(int n) {
    if (n <=1) {
        return n;
    }
    else return fib_recurrency(n - 1) + fib_recurrency(n - 2);
}

int fib_for(int n ) {
    std::ofstream File("fib.txt");
    std::vector<int> p={0,1};
    for (int i{0}; i <= n; i++) {
        if (i>=2) {
            int sum = p[i-1] + p[i-2];
            p.push_back(sum);
        }
        File<<i<<": "<<p[i]<<std::endl;
    }
    return p[n];
    File.close();
};

