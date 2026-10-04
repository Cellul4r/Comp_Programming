/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){

    // #1s must be divisble by n and one >= n
    // thus each array must contain one = one / n <= m
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> cnt(n, 0);
    int one = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            if(a[i][j] == 1) {
                one++;
                cnt[i]++;
            }
        }
    }
    // this is correct
    if((one > 0 && one < n) || one % n != 0 || one / n > m) {
        cout << -1 << nl;
        return;
    }
    // how to answer minimum operation efficiently?
    // need to swap same index!!!
    // observation the number of 1 in each column never change after doing operations it just change which 1 will be in what array
    int need = one / n;
    vector<array<int,3>> ans;
    for(int i = 0; i < m; i++) {
        // fixed position to change
        // if type 1 need to swap 1 to someelse array
        // else type 2 need to get #1 to equal to need
        vector<int> idx[2];
        for(int j = 0; j < n; j++) {
            if(cnt[j] < need && a[j][i] == 0) {
                idx[1].push_back(j);
            } else if(cnt[j] > need && a[j][i] == 1) {
                idx[0].push_back(j);
            }
        }
        // sliding between 2 array until someone end at the end of array we can't do anymore
        // idx[0].size >= idx[1].size
        int j = 0, k = 0;
        while(j < (int)idx[0].size() && k < (int)idx[1].size()) {
            ans.push_back({idx[0][j],idx[1][k],i});
            cnt[idx[0][j]]--;
            cnt[idx[1][k]]++;
            j++;
            k++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(cnt[i] != need) {
            cout << -1 << nl;
            return;
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] + 1 << " " << x[1] + 1 << " " << x[2] + 1 << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

