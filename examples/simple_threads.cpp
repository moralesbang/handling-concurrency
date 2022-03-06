#include<iostream>
#include<thread>

using namespace std;

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

    thread t1(sumEven, start, end);
    thread t2(sumOdd, start, end);

    t1.join();
    t2.join();

    cout << "Odd Sum: " << odd_sum << endl;
    cout << "Even Sum: " << even_sum << endl;

    return 0;
}