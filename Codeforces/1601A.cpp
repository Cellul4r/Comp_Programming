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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<int> bits(30);
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j] & (1 << i)) {
                bits[i]++;
            }
        }
    }

    int gcd_ = 0;
    for(int i = 0; i < 30; i++) {
        gcd_ = gcd(bits[i], gcd_);
    }

    for(int i = 1; i <= n; i++) {
        if(gcd_ % i == 0) {
            cout << i << " ";
        }
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

