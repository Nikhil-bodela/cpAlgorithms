#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    int row , col;
    cin >> row >> col;
    vector<vector<int>>grid(row , vector<int>(col));
    for(int r = 0 ; r < row ; r++) {
        for(int c = 0 ; c < col ; c++){
            cin >> vector[r][c];
        }
    }
}
