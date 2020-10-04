#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int main() {
    int num_steps = 1e6;
    double x, pi, sum = 0.0;
    double step = 1.0 / num_steps;
    double partial_sum = 0;
    auto startTime = high_resolution_clock::now();
    for(int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        partial_sum = 4.0 / (1.0 + x * x);
        sum += partial_sum;
    }
    auto endTime = high_resolution_clock::now();
    auto UniProcDuration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "The calculated Pi value is: " << sum * step << endl;
    cout << "Execution Time: " << UniProcDuration << " microseconds.\n";
}