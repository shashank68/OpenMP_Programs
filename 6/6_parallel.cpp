#include<bits/stdc++.h>
#include<omp.h>

using namespace std;
using namespace std::chrono;

int main() {
    int num_steps = 1e6;
    double pi, sum = 0.0;
    omp_set_num_threads(8);
    double step = 1.0 / num_steps;
    auto startTime = high_resolution_clock::now();
    {
        #pragma omp parallel 
        {
            double x;
            int i;
            #pragma omp for reduction(+:sum)
            for(i = 0; i < num_steps; i++) {
                x = (i + 0.5) * step;
                sum += 4.0 / (1.0 + x * x);
            }
        }
    }
    auto endTime = high_resolution_clock::now();
    auto ParallelProcDuration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "The calculated Pi value is: " << sum * step << endl;
    cout << "Execution Time: " << ParallelProcDuration << " microseconds.\n";
}