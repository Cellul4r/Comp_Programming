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

void readFile(string);
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i-1]) > m) {
            if(a[i] < a[i-1]) {
                a[i] = a[i-1] - m;
            } else {
                a[i-1] = a[i] - m;
            }
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        if(abs(a[i] - a[i+1]) > m) {
            if(a[i] < a[i+1]) {
                a[i] = a[i+1] - m;
            } else {
                a[i+1] = a[i] - m;
            }
        }

    }

    for(auto &x : a) cout << x << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //readFile("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void readFile(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

