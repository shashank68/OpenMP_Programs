#include<bits/stdc++.h>
#include<omp.h>

using namespace std;
using namespace std::chrono;

static int mul = 16807;
static int add = 3;
static int mod = INT_MAX;

double rand_om(long long& rand_om_val) {
    rand_om_val = 1.0 * ((mul * rand_om_val + add) % mod);
    return 1.0 * rand_om_val / mod;
}


int main() {
    int N_trials = 1e8;
    int cnt = 0;
    auto startTime = high_resolution_clock::now();
    #pragma omp parallel
    {
        double x, y;
        long long rand_om_val = time(0)/(1e5) + (1e5) * omp_get_thread_num();
        #pragma omp for reduction(+:cnt)
        for(int i = 0; i < N_trials; i++) {
            x = 1.0 * rand_om(rand_om_val);
            y = 1.0 * rand_om(rand_om_val);
            if(x*x + y*y <= 1.0) cnt++;
        }
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime-startTime).count();
    cout << "PI value obtained is: " << 4.0 * (double)cnt / N_trials << endl;
    cout << "Execution time: " << duration << " milliseconds.\n";
}