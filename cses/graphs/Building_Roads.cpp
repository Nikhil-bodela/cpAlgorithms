#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
set<int>visited;
set<int>unVisited;
unordered_map<int ,vector<int>>mp;
vector<pair<int , int>>res;
// vector<int>par;
// int find(int x){
//     if(par[x] == x){
//         return par[x];
//     }
//     return par[x] = find(par[x]);
// }
// void unite(int a , int b){
//     int pa = find(a) , pb = find(b);
//     if(pa > pb) swap(a , b);
//     par[b] = pa;
// }
void dfs(int node){
    visited.insert(node);
    unVisited.erase(node);
    for(int child : mp[node]){
        if(!visited.count(child) )dfs(child);
    }

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m ;
    cin >> n >> m;
    visited.clear();
    unVisited.clear();
    mp.clear();
    res.clear();
    for(int i = 1 ; i <= n ; i++) {
        unVisited.insert(i);
    }
    while(m--){
        int u , v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    while (!unVisited.empty()) {
        int node = *unVisited.begin(); 
        if (!visited.empty()) {
            res.push_back({*visited.begin(), node});
        }
        dfs(node);
    }

    cout << res.size() << '\n';
    for(auto edge : res){
        cout << edge.first << ' ' << edge.second << '\n';
    }
    return 0;
}

