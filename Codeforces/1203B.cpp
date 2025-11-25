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
    
    int n; cin>>n;
    vector<int> cnt(1e4+1);
    for(int i = 1; i <= 4*n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }

    int l = 1, r = 1e4;
    bool ok = true;
    int area = -1;
    while(l < r) {
        if(cnt[l] == 0) {
            l++;
            continue;
        }
        if(cnt[r] == 0) {
            r--;
            continue;
        }
        if(cnt[l] != cnt[r] || cnt[l] % 2 != 0) {
            ok = false;
            break;
        }
        if(area == -1) {
            area = l * r;
        } else if(area != l * r) {
            ok = false;
            break;
        }
        l++;
        r--;
    }

    if(l == r && cnt[l] > 0) {
        if(cnt[l] % 4 != 0 || (area != -1 && l * l != area)) {
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << nl;
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

