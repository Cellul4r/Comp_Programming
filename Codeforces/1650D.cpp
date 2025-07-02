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
    
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        x--;
        pos[x] = i;
    }

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--) {
        //cerr << i << " " << pos[i] << nl;
        if(pos[i] > i) {
            ans[i] = pos[i] - i;
        } else if(pos[i] < i) {
            ans[i] = pos[i] + i + 1 - i;
        }

        for(int j = 0; j <= i; j++) {
            pos[j] = (pos[j]-ans[i]+i+1)%(i+1);
        }
    }

    for(auto &x : ans) {
        cout << x << " ";
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

