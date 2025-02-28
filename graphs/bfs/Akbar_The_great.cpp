#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, r, m;
        cin >> n >> r >> m;

        vector<vector<int>> adjList(n + 1);
        for (int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> guard(n + 1, -1); 
        vector<pair<int, int>> strength;
        for (int i = 0; i < m; i++) {
            int k, s;
            cin >> k >> s;
            strength.push_back({k, s});
        }

        queue<pair<int, int>> q; 
        for (auto& [node, s] : strength) {
            if (guard[node] != -1) { 
                cout << "No\n";
                goto next_test_case;
            }
            q.push({node, s});
            guard[node] = node; 
        }

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();
            if (steps == 0) continue; 

            for (int neighbor : adjList[cur]) {
                if (guard[neighbor] == -1) {
                    guard[neighbor] = guard[cur]; 
                    q.push({neighbor, steps - 1});
                } else if (guard[neighbor] != guard[cur]) {
                    cout << "No\n";
                    goto next_test_case;
                }
            }
        }

        if (count(guard.begin() + 1, guard.end(), -1) == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

        next_test_case:; 
    }
    return 0;
}
