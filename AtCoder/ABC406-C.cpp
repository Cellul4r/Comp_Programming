/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
vector<int> a;
void solve(){

    cin>>n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    ll ans = 0;
    vector<pair<int,int>> now;
    for(int i = 2; i < n; i++) {
        if(a[i-1] < a[i] && a[i] > a[i+1]) {
            now.push_back(make_pair(i,1));
        } else if(a[i-1] > a[i] && a[i] < a[i+1]) {
            now.push_back(make_pair(i,2));
        }
    }

    int prev_ = -1;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++) {
        pre[i] += pre[i-1];
        if(a[i] > a[i-1]) pre[i]++;
    }
    for(int i = 0; i < (int)now.size() - 1; i++) {
        if(now[i].second == now[i+1].second) continue;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

