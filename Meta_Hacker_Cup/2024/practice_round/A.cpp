#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

void solve() {
    
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    ll min_ = LLONG_MAX;
    for(auto &x:a) {
        cin>>x;
        min_ = min(min_, x);
    }
    ll walkTime;
    if(n == 1) walkTime = min_;
    else {
        walkTime = min_ * (2*n - 3);
    }
    cout << (walkTime <= k ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;

    for(int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

