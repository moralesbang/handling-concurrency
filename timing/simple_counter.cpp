#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull even_sum = 0;
ull odd_sum = 0;

void sumEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if (i % 2 == 0) {
            even_sum += i;
        }
    }
}

void sumOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if (i % 2 == 1) {
            odd_sum += i;
        }
    }
}


int main() {
    ull start = 0, end = 1900000000;

    auto start_time = high_resolution_clock::now();

    sumEven(start, end);
    sumOdd(start, end);

    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_time - start_time);

    cout << "Odd Sum: " << odd_sum << endl;
    cout << "Even Sum: " << even_sum << endl;
    cout << "\nElapsed Time: " << duration.count() /  1000000 << " s" << endl;

    return 0;
}