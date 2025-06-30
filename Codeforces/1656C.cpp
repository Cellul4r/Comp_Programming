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
    bool zero = false, one = false, two = false;
    for(auto &x : a) {
        cin>>x;
        if(x == 0) {
            zero = true;
        } else if(x == 1) {
            one = true;
        } else if(x == 2) {
            two = true;
        }
    }
    sort(all(a));
    if(one && zero) {
        cout << "NO" << nl;
        return;
    }

    if(one) {
        bool flag = two;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] == a[i+1] - 1) {
                flag = true;
            }
        }
        if(flag) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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

