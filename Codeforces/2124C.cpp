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
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }

    // ai dividi ai+1
    // then ai divide ai+2, ai+3, ..., an
    //cerr << gd << nl;
    // a[0] != gd ? then a[0] > gd then let x = a[0] / g
    int x = 1;
    for(int i = 1; i < n; i++) {
        if(b[i] % b[i-1] != 0) {
            b[i-1] /= x;
            int gd = __gcd(b[i-1],b[i]);
            if(b[i] % b[i-1] != 0) {
                x *= (b[i-1] / gd);
                b[i-1] /= x;
            }
        }
    }
    /*for(int i = 0; i < n; i++) {
        cerr << b[i] << " ";
    }*/
    cout << x << nl;
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

