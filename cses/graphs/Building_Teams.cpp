#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<int>res;
vector<int>visited;
unordered_map<int , vector<int>>adj;
bool flag;
void dfs(int node ){
    for(int child : adj[node]){
        if(child != node && res[node] == res[child])flag = true;
        if(!visited[child]){
            res[child] = 1-res[node];
            visited[child] = 1;
            dfs(child);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m ;
    cin >> n >> m;
    adj.clear();
    for(int i = 0 , u , v ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    res.clear();
    res.resize(n+1 , -1);
    visited.clear();
    visited.resize(n+1 , 0);
    flag = false;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            res[i] = 1;
            visited[i] = 1;
            dfs(i);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE";
    }else{
    for(int i = 1; i <= n ; i++) {
        cout << 2-res[i] << ' ';
    }
    cout << '\n';
}
    return 0;
}

