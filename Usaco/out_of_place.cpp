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
const int N =101;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

vector<int> a;
void solve(){
    
    int n;
    cin>>n;
    a.resize(n);
    int bessie = -1;
    for(int i = 0; i < n; i++) cin>>a[i];
    // find the position that bessie is imposter
    for(int i = 0; i < n; i++) {
        //suppose i is bessie
        bool valid = true;
        vector<int> b(n-1);
        for(int j = 0, k = 0; j < n; j++) {
            if(i == j) continue;
            b[k++] = a[j];
        }
        for(int i = 0; i < n - 2; i++) {
            cerr << b[i] << " ";
            if(b[i] > b[i+1]) {
                valid = false;
            }
        }
        cerr << nl;
        if(valid) {
            bessie = i;
            break;
        }
    }
    cerr << bessie << nl;
    int prev_ = -1;
    int ans = 0;
    while(true) {
        if(bessie != n - 1 && a[bessie] > a[bessie + 1]) {
            if(prev_ != a[bessie+1]) {
                ans++;
                prev_ = a[bessie + 1];
            }
            a[bessie + 1] = a[bessie];
            bessie++;
        } else if(bessie != 0 && a[bessie] < a[bessie - 1]) {
            if(prev_ != a[bessie - 1]) {
                ans++;
                prev_ = a[bessie - 1];
            }
            a[bessie - 1] = a[bessie];
            bessie--;
        } else {
            break;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

