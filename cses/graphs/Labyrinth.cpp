#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m ;
    cin >> n >> m;
    pair<int , int >start , end;
    vector<vector<char>>grid(n , vector<char>(m));
    for(int i = 0 ; i < n ; i++){
        string line;
        cin >> line;
        for(int j = 0 ; j < m ; j++){
            grid[i][j] = line[j];
            if(line[j] == 'A')start = {i , j};
            if(line[j] == 'B')end = {i , j};
        }
    }
    vector<vector<int>>par(n , vector<int>(m , -1));
    vector<pair<int ,int>>dir{{-1,0},{1,0} , {0 , 1} , {0 , -1}};
    queue<pair<int , int>>q;
    q.push(start);
    grid[start.first][start.second] = '#';
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int newR = node.first + dir[i].first ; 
            int newC = node.second + dir[i].second;
            if(newR >= 0 && newC >=0 && newR < n && newC < m && grid[newR][newC] != '#'){
                par[newR][newC] = i;
                grid[newR][newC] = '#';
                q.push({newR , newC});
            }

        }
    }
    if(par[end.first][end.second] == -1){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        string path = "UDRL";
        string res = "";
        int r = end.first , c = end.second;
        while(r!= start.first || c  != start.second){
            res += path[par[r][c]];
            int j = par[r][c];
            r -= dir[j].first;
            c -= dir[j].second;
        }
        cout<<res.size() << '\n';
        reverse(res.begin() ,res.end());
        cout << res << '\n';
    }
    return 0;
}


