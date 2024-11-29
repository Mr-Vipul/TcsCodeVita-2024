#include <bits/stdc++.h>
using namespace std;

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> ids(N), costs(N);
    for (int i = 0; i < N; i++) {
        cin >> ids[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }
    
    int A;
    cin >> A;
    
    int maxFreeItems = 0;
    int maxFreeWorth = 0;
    
    for (int i = 0; i < N; i++) {
        for (int qty = 1; qty <= A / costs[i]; qty++) {
            int totalCost = qty * costs[i];
            vector<int> freeItems;
            int freeWorth = 0;
            
            vector<int> factors = getFactors(ids[i]);
            
            for (int j = 0; j < N; j++) {
                if (find(factors.begin(), factors.end(), ids[j]) != factors.end() && j != i) {
                    freeItems.push_back(j);
                    freeWorth += costs[j];
                }
            }
            
            int currFreeItems = freeItems.size() * qty;
            int currFreeWorth = freeWorth * qty;
            
            if (totalCost <= A) {
                if (currFreeItems > maxFreeItems || 
                    (currFreeItems == maxFreeItems && currFreeWorth > maxFreeWorth)) {
                    maxFreeItems = currFreeItems;
                    maxFreeWorth = currFreeWorth;
                }
            }
        }
    }
    
    cout << maxFreeItems << " " << maxFreeWorth;
    
    return 0;
}