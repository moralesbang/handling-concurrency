#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int current_count = 0;
mutex critical_section;

void increment(int n) {
    critical_section.lock();
    for (int i = 0; i < n; ++i) {
        ++current_count;
    }
    critical_section.unlock();
}

int main() {
    auto start_time = high_resolution_clock::now();

    thread t1(increment, 99999);
    thread t2(increment, 99999);

    t1.join();
    t2.join();

    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_time - start_time);

    cout << "Current count: " << current_count << endl;
    cout << "Elapsed time: " << duration.count() << " µs" << endl;
    
    return 0;
}