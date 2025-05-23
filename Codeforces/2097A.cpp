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

void solve(){
    
    int n;
    cin>>n;
    map<int,int> cnt;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
        cnt[x]++;
    }
    
    for(int i = 0; i < n; i++) {
        int x = a[i];
        if(cnt[x] >= 4) {
            cout << "YES" << nl;
            return;
        }
        // predict this student with x+1 x <= 3
        int b = cnt[x-1], c = cnt[x+1];
        bool ok = false;
        if(cnt[x] == 1) {
            for(int j = 0; j < 2; j++) {
                b = cnt[x-1], c = cnt[x+1];
                if(j) {
                    b++;
                } else {
                    c++;
                }
                if(b >= 2 && c >= 2) {
                    ok = true;
                }
            }
        } else if(cnt[x] == 2) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    b = cnt[x-1], c = cnt[x+1];
                    if(j) b++;
                    else c++;
                    if(k) b++;
                    else c++;
                    if(b >= 2 && c >= 2) {
                        ok = true;
                    }
                }
            }
        } else if(cnt[x] == 3) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    for(int l = 0; l < 2; l++) {
                        b = cnt[x-1], c = cnt[x+1];
                        if(j) b++;
                        else c++;
                        if(k) b++;
                        else c++;
                        if(l) b++;
                        else c++;
                        cerr << j << " " << k << " " << l << nl;
                        cerr << b << " " << c << nl;
                        if(b >= 2 && c >= 2) {
                            ok = true;
                        }
                    }
                }
            }
        }
        if(ok) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

