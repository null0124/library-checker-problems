#include <iostream>
#include <tuple>
#include "random.h"

using namespace std;

int main(int, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = 40;    
    int m = gen.uniform(0, n * (n - 1) / 2);

    using P = pair<int, int>;
    vector<P> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gen.uniform_bool()) {
                edges.push_back({i, j});
            } else {
                edges.push_back({j, i});
            }
        }
    }
    gen.shuffle(edges.begin(), edges.end());
    edges.resize(m);

    cout << n << " " << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << edges[i].first << " " << edges[i].second << "\n";
    }
    return 0;
}