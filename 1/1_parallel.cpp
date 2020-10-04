#include<omp.h>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int main() {
    auto startTime = high_resolution_clock::now();
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf(" Hello Parallel World from thread(%d)\n", ID);
    }
    auto endTime = high_resolution_clock::now();
    auto UniProcDuration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "Execution Time: " << UniProcDuration << " microseconds.\n";
}