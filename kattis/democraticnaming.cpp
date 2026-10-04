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

    int n,m; cin>>n>>m;
    vector<string> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    string ans;
    for(int i = 0; i < m; i++) {
        vector<int> freq(26);
        for(int j = 0; j < n; j++) {
            freq[a[j][i] - 'a']++;
        }
        int mx = 0, cur = -1;
        for(int k = 0; k < 26; k++) {
            if(freq[k] > mx) {
                cur = k;
                mx = freq[k];
            }
        }
        ans += cur + 'a';
    }
    cout << ans;
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

