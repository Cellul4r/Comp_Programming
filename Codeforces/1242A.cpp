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
    
    ll n; cin>>n;
    // trivial observation
    // if n is prime number -> answer = n different colors
    // 6 
    // prime factorization
    // 2, 3, 5
    // 2, 4, 6, 8, 10, 12, ...
    // 3, 9, 27, 3^4, ...
    // 5, 10, 15, 20, 25, 30, ...
    vector<ll> prime;
    ll tmp = n;
    for(ll d = 2; d * d <= n; d++) {
        int cnt = 0;
        while(tmp % d == 0) {
            cnt++;
            tmp /= d;
        }
        if(cnt == 0) continue;
        prime.push_back(d);
    }
    // 3*5
    // 1,2,3, 4,5,6, 7,8,9, 10,11,12, 13,14,15, 16,17,18
    // 1,2,3, 6,7,8, 11,12,13
    if(tmp > 1 && tmp < n) {
        prime.push_back(tmp);
    }
    if(prime.empty()) {
        cout << n;
        return;
    }
    if(prime.size() == 1) {
        cout << prime[0];
        return;
    }
    cout << 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

