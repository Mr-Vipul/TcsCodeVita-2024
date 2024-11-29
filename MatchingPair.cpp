#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int squaredDistance(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // If there's only one earring or less, there's no pair to find
    if (N < 2) {
        cout << "No matching pair found.";
        return 0;
    }

    vector<vector<int>> earringEdges(N); // Store the edge distances for each earring

    // Read each earring and calculate its edge distances
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        if (K < 3) {
            cout << "Each earring must have at least 3 vertices.";
            return 0;
        }

        vector<Point> points(K);
        for (int j = 0; j < K; j++) {
            cin >> points[j].x >> points[j].y;
        }

        // Calculate the squared distances between consecutive points
        vector<int> edges;
        for (int j = 0; j < K; j++) {
            int next = (j + 1) % K; // Next point (wraps around at the end)
            edges.push_back(squaredDistance(points[j], points[next]));
        }

        earringEdges[i] = edges; // Store the edge distances
    }

    bool found = false;
    int e1 = -1, e2 = -1;

    // Compare each pair of earrings
    for (int i = 0; i < N && !found; i++) {
        for (int j = i + 1; j < N && !found; j++) {
            // If the earrings have different numbers of edges, skip them
            if (earringEdges[i].size() != earringEdges[j].size()) continue;

            int K = earringEdges[i].size();
            // Check if one earring is a rotated version of the other
            for (int s = 0; s < K && !found; s++) {
                bool match = true;
                for (int k = 0; k < K; k++) {
                    // Compare edges of earring i with rotated edges of earring j
                    if (earringEdges[i][k] != earringEdges[j][(k + s) % K]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    e1 = i + 1;
                    e2 = j + 1;
                    found = true;
                }
            }
        }
    }

    // Output the result
    if (found) {
        cout << e1 << " " << e2;
    } else {
        cout << "No matching pair found.";
    }

    return 0;
}