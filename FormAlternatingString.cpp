#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length(), res = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int lw = s[0] - '0', lwv = v[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] - '0' == lw) {
            res += min(lwv, v[i]);
            lwv = max(lwv, v[i]);
        } else {
            lw = s[i] - '0';
            lwv = v[i];
        }
    }
    cout << res;
    return 0;
}
