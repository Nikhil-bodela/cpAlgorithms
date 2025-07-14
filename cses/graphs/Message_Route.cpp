#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m ;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0 , u , v ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n+1 , 0);
    vector<int>par(n+1 , -1);
    vector<int>res;
    // queue<pair<int,int>>q;
    // q.push({1, 0});
    // visited[1] = 1;
    // while(!q.empty()){
    //     auto pi = q.front();
    //     int node = pi.first;
    //     par[node] = pi.second;
    //     q.pop();
    //     if(node == n){
    //         int a = node;
    //         while(a != 0){
    //             res.push_back(a);
    //             a = par[a];
    //         }
    //         break;
    //     }
    //     for(int child : adj[node]){
    //         if(!visited[child]){
    //             q.push({child , node});
    //             visited[child] = 1;
    //         }
    //     }
    // }
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int child : adj[node]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
                par[child] = node;
            }
        }
    }
    // if(res.size() == 0){
    //     cout << "IMPOSSIBLE";
    // }
    // else{
    //     cout << res.size() << '\n';
    //     for(int i = res.size()-1 ; i >= 0 ; i--){
    //         cout << res[i] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(!visited[n]){
        cout << "IMPOSSIBLE";
    }
    else{
        int a = n;
        while(a != -1){
            res.push_back(a);
            a = par[a];
        }
        cout << res.size() << '\n';
        for(int i = res.size()-1 ; i >= 0 ; i--){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

