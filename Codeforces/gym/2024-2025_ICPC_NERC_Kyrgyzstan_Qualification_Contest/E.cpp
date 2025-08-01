#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
typedef long long ll;
int n,m;
int h[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>h[i];
    }
    bool found = false;

    auto f = [&](ll k) {
        //cerr << k << endl;
        int group = 1;
        for(int i = 1; i < n; i++) {
            if(abs(h[i] - h[i-1]) > k) {
                group++;
            }
        }
        return group;
    };
    ll l = 1, r = 1e12; 
    ll ans = -1;
    while(l <= r) {
        ll mid = l + (r - l) / 2ll;
        ll x = f(mid);
        if(x > m) {
            l = mid + 1;
        } else if(x == m){
            ans = mid;
            found =true;
            r = mid - 1;
        } else {
            r = mid - 1;
        }
    }
    cout << (found ? ans : -1);

    return 0;
}
