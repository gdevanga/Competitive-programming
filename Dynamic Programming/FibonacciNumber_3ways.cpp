//
//  main.cpp
//  Fibonacci Series
//
//  Created by Girish Devanga on 23/12/19.
//  Copyright © 2019 Girish Devanga. All rights reserved.
//

#include <iostream>

int fib1 (int n) {
    if (n == 1 || n == 0) return 1;
    return fib1(n-1) + fib1(n-2);
}

int auxFib2 (int n, int* mem) {
    //if (n == 1 || n == 0) return 1;
    if (mem[n] != 0)
        return mem[n];
    mem[n] = auxFib2(n-1, mem) + auxFib2(n-2, mem);
    return mem[n];
}

int fib2 (int n) {
    int* mem = new int[n+1];
    for (int i = 0; i < n+1; ++i)
        mem[i] = 0;
    mem[0] = mem[1] = 1;
    return auxFib2(n, mem);
}

int fib3 (int n) {
    int* mem = new int[n+1];
    mem[0] = mem[1] = 1;
    for (int i = 2; i < n+1; ++i)
        mem[i] = mem[i-1] + mem[i-2];
    return mem[n];
}

int main(int argc, const char * argv[]) {

    std::cout << "fib1  for " << argv[1] << ": " << fib1(atoi(argv[1])) << std::endl;
    std::cout << "fib2  for " << argv[1] << ": " << fib2(atoi(argv[1])) << std::endl;
    std::cout << "fib3  for " << argv[1] << ": " << fib3(atoi(argv[1])) << std::endl;
    return 0;
}
