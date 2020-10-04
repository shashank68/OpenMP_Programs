#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int main() {
    auto startTime = high_resolution_clock::now();
    for(int i = 0; i < 8; i++)
        printf(" Hello Serial World!!\n");
    auto endTime = high_resolution_clock::now();
    auto UniProcDuration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "Execution Time: " << UniProcDuration << " microseconds.\n";
}