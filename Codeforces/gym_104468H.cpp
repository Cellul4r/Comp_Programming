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
const int N =2e5+10;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    cin>>n;
    vector<vector<ll>> colors(N, vector<ll>{0});
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        colors[x].push_back(a[i]);
    }
    ll sum = 0;
    int q;
    cin>>q;
    vector<ll> minus(N);
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < (int)colors[i].size(); j++) {
            colors[i][j] += colors[i][j-1]; 
        }
    }
    for(int i = 0; i < q; i++) {
        int type,col;
        ll val;
        cin>>type>>col>>val;
        if(type == 1) {
            sum += val;
            minus[col] += val;
        } else {
            int l = 1, r = colors[col].size() - 1;
            l--;
            while(l < r) {
                int mid = l + (r - l + 1) / 2;
                //cerr << mid << nl;
                if(colors[col][mid] + (ll)mid * (sum - minus[col]) <= val) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            cout << l << nl;
        }
    }
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

