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

void setIO(string);
void solve(){
    
      ll n,a;
      cin>>n>>a;
      vector<ll> v(n);
      for(auto &x : v) {
          cin>>x;
      }

      int idx1 = -1, idx2 = -1;
      ll val = 0, ans = -1;
      for(int i = 0; i < n; i++) {
          if(v[i] < a) {
              idx1 = i;
          }
          if(v[i] > a && idx2 == -1) {
              idx2 = i;
          }
      }
      if(idx1 != -1 && idx1 + 1 > val) {
          ans = v[idx1];
          val = idx1 + 1;
      }
      if(idx2 != -1 && n - idx2 > val) {
          ans = v[idx2];
      }
      if(ans == -1) {
          ans = v[0];
      }
      cout << ans << nl;
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

