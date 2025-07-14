#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(vector<vector<char> >&grid , int r ,int c){
    int row = grid.size() , col = grid[0].size();
    vector<pair<int,int>>dir{{-1,0},{0 , -1},{1 , 0} ,{0 , 1}};
    grid[r][c] = '#';
    for(pair pi : dir){
        int newr = r + pi.first , newc = c + pi.second;
        if(newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] == '.')dfs(grid , newr , newc);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m;
    cin >> n ;
    cin >> m ;
    vector<vector<char>>grid(n , vector<char>(m));
    for(int i = 0 ; i < n ; i++){
        string line;
        cin >> line;
        for(int j = 0 ; j < m ; j++)grid[i][j] = line[j];
    }
    int res = 0 ; 
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            if(grid[r][c] == '.'){
                // cout << r << c;
                dfs(grid , r , c);
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}

