#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve(){
    int row , col;
    cin >> row >> col;
    vector<vector<int>>grid(row , vector<int>(col));
    for(int r = 0 ; r < row ; r++) {
        for(int c = 0 ; c < col ; c++){
            cin >> grid[r][c];
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(row , vector<bool> (col , false));
    for(int r = 1 ; r < row-1 ; r++){
        pq.push({grid[r][0] ,{r , 0}});
        pq.push({grid[r][col-1] , {r ,col-1}});
        visited[r][0] = true;
        visited[r][col-1]=true;
    }
    for(int c = 0 ; c < col ; c++) {
        pq.push({grid[0][c] , {0 , c}});
        pq.push({grid[row-1][c] ,{row-1 , c}});
        visited[0][c] = true;
        visited[row-1][c] = true;
    }

    int res = 0;
    vector<vector<int>> dir{{0, 1} , {0 , -1} , {1 ,0} ,{-1 ,0}};
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int currHeight = top.first;
        int currRow = top.second.first;
        int currCol = top.second.second;
        for(auto& d : dir) {
            int newRow = currRow + d[0] , newCol = currCol + d[1];
            if(0<=newRow && newRow<row && 0<=newCol && newCol<col && !visited[newRow][newCol]){
                res += max(0 , currHeight - grid[newRow][newCol]);
                pq.push({max(currHeight ,grid[newRow][newCol]) , {newRow , newCol}});
                visited[newRow][newCol] = true;
            }
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

