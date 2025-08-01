#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    ll l = 0, r = 1e12;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        bool ok = true;
        ll now = mid;
        for(auto &x : a) {
            now += x;
            if(now < 0) {
                ok = false;
            }
        }
        if(ok) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
