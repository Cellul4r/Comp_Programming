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

void solve(){

    int n;
    cin>>n;
    map<int,int> save;
    int now = 0;
    int ans = 0;
    // important!
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        now += x;
        now %= 7;
        if(save[now] == 0) {
            save[now] = i;
        } else {
            ans = max(ans,i - save[now]);
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    string s = "div7";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

