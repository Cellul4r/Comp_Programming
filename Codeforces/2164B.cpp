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
    int even = 0;
    for(auto &x : a) {
        cin>>x;
        if(x % 2 == 0) even++;
    }

    if(even >= 2) {
        int x = -1, y=-1;
        for(auto &k : a) {
            if(k % 2 == 0) {
                if(x == -1) {
                    x = k;
                } else {
                    y = k;
                }
            }
        }
        cout << x << " " << y << nl;
        return;
    }

    // odd matching
    bool ok = false;
    int x=-1,y=-1;
    if(a[0] == 1) {
        ok = true;
        x = a[0];
        y = a[1];
    } else {
        for(auto &k : a) {
            if(k & 1) {
                x = k;
                break;
            }
        }
        for(auto &k : a) {
            if(k > x && (k % x) % 2 == 0) {
                ok = true;
                y = k;
                break;
            }
        }


    }

    if(!ok) {
        for(auto &k : a) {
            if((k & 1) && x != k) {
                x = k;
                break;
            }
        }
        for(auto &k : a) {
            if(k > x && (k % x) % 2 == 0) {
                ok = true;
                y = k;
                break;
            }
        }
    }

    if(!ok) {
        for(auto &k : a) {
            if(k % 2 == 0) {
                y = k;
                break;
            }
        }
        for(auto &k : a) {
            if(k % 2 == 1 && y > k && (y % k) % 2 == 0) {
                ok = true;
                x = k;
                break;
            }
        }
    }

    if(!ok) {
        int prv = -1;
        for(auto &k : a) {
            if(k % 2 == 0) continue;
            if(prv == -1) {
                prv = k;
                continue;
            }
            if(k % prv % 2 == 0) {
                ok = true;
                y = k;
                x = prv;
                break;
            }
            prv = k;
        }
    }
    if(!ok) {
        cout << -1 << nl;
        return;
    }
    cout << x << " " << y << nl;
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

