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
    int x=-1,y=-1;

    for(int i = 0; i < n && x == -1; i++) {
        for(int j = i+1; j < n; j++) {
            if((a[j] % a[i]) % 2 == 0) {
                x = a[i];
                y = a[j];
                break;
            }
        }
    }

    if(x == -1) {
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

