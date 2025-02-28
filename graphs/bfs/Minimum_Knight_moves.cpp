#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    while (t--) {
        string in, out;
        cin >> in >> out;

        queue<pair<int, int>> q;
        q.push({in[0] - 'a', in[1] - '1'});

        vector<vector<bool>> visited(8, vector<bool>(8, false));
        visited[in[0] - 'a'][in[1] - '1'] = true;

        vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, 
                                      {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                if (r == out[0] - 'a' && c == out[1] - '1') {
                    cout << ans << '\n';
                    goto nextTestCase;
                }

                for (auto [x, y] : dir) {
                    int newx = r + x;
                    int newy = c + y;
                    if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8 && !visited[newx][newy]) {
                        q.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
            }
            ans++;
        }
    nextTestCase:;
    }
    return 0;
}
