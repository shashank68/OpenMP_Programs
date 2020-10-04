#include<bits/stdc++.h>
#include<omp.h>

using namespace std;
using namespace std::chrono;

int main() {
    const int MAX_THREADS = 14, n = 1 << 16;
    double a = 3.14, max_speedup = 1.0;
    int max_speed_threads_N = -1;
    vector<double> X_Common(n), Y_Common(n);
    for(int i = 0; i < n; i++) {
        X_Common[i] = (rand() % 10000) * 1.618;
        Y_Common[i] = (rand() % 10000) * 1.618;
    }
    vector<double> X(X_Common.begin(), X_Common.end()), Y(Y_Common.begin(), Y_Common.end());
    /********************************************************************************************************************************************/
    // Uniprocessor loop;
    auto startTime = high_resolution_clock::now();
    for(int i = 0; i < n; i++) {
        X[i] = a * X[i] + Y[i];
    }
    auto endTime = high_resolution_clock::now();
    auto UniProcDuration = duration_cast<microseconds>(endTime - startTime).count();
    /********************************************************************************************************************************************/
    cout << "Uniprocessor execution time: " << UniProcDuration << " microseconds." << endl;
    cout << "=========================================================================" << endl;

   // Parallel processing 
    for(int N_threads = 2; N_threads <= MAX_THREADS; N_threads++) {
        X = X_Common, Y = Y_Common;
        /************************************************************************************************************************************/
        omp_set_num_threads(N_threads);
        startTime = high_resolution_clock::now();
        #pragma omp parallel for
        for(int i = 0; i < n; i++) {
            X[i] = a * X[i] + Y[i];
        }
        /************************************************************************************************************************************/
        endTime = high_resolution_clock::now();
        auto ParallelProcDuration = duration_cast<microseconds>(endTime - startTime).count();
        double speed_up = ParallelProcDuration * 1.0 / UniProcDuration;
        if(speed_up < max_speedup) {
            max_speedup = speed_up;
            max_speed_threads_N = N_threads;
        }
        cout << "Number of threads: " << N_threads << "; Execution Time of for loop: " << ParallelProcDuration << " microsec; SpeedUp (Tn / T1): " << ParallelProcDuration*1.0 / UniProcDuration << endl;
    }
    cout << "=========================================================================" << endl;
    if(max_speed_threads_N != -1) {
        cout << "Maximum Speed was achieved with " << max_speed_threads_N << " threads." << endl;
        cout << "Maximum speed(Parallel) was " << 1.0 / max_speedup << " times faster than Uniprocessing speed.\n";
    } else {
        cout << "Parallelised for loop was not faster than Uni-processor execution!!" << endl;
    }
}