// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <math.h>


bool checkPrime(uint64_t value) {
    bool result = true;

    if (value == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

uint64_t nPrime(uint64_t n) {
    int counter = 0;
    int i = 1;

    while (counter != n) {
        counter += checkPrime(i);
        i++;
    }

    i--;
    return i;
}

uint64_t nextPrime(uint64_t value) {
    int flag = 0;

    while (flag == 0) {
        flag += checkPrime(value + 1);
        value++;
    }

    return value;
}

uint64_t pastPrime(uint64_t value) {
    int flag = 0;

    while (flag == 0) {
        flag += checkPrime(value - 1);
        value--;
    }

    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    int sum;

    if (hbound < 3) {
        sum = 0;
    }

    if (hbound >= 3) {
        sum = pastPrime(hbound) + sumPrime(pastPrime(hbound));
    }

    return sum;
}
