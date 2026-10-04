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
    
    int n; cin>>n;
    vector<ll> b(n);
    map<ll, vector<int>> save;
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        save[b[i]].push_back(i);
    }

    // assumption: if b[i] = b[j] -> a[i] = a[j]
    vector<ll> a(n, 1);
    ll sum = 0, mx = 0;
    ll cur = -1;
    for(auto &[x,y] : save) {
       if(cur == -1) {
           if(x != 0) {
               cout << -1 << nl;
               return;
           }
           cur = x;
           continue;
       }
       ll now = x - sum;
       ll sz = save[cur].size();
       if(now % sz != 0 || now / sz <= mx) {
           cout << -1 << nl;
           return;
       }
       for(auto &e: save[cur]) {
           a[e] = now / sz;
       }
       sum += now;
       mx = now / sz;
       cur = x;
    }
    for(auto &x : save[cur]) {
       a[x] = mx + 1; 
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << nl;
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

