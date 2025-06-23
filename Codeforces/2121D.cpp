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
    vector<int> a(n),b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    vector<pi> ans;

    for(int i = 0; i < n - 1; i++) {
        bool found = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                found = true;
                //cerr << j + 1 << " " << j << nl;
                ans.push_back(make_pair(1,j));
                swap(a[j], a[j+1]);
            }
        }
        if(!found) break;
    }
    for(int i = 0; i < n - 1; i++) {
        bool found = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(b[j] > b[j+1]) {
                found = true;
                //cerr << j + 1 << " " << j << nl;
                ans.push_back(make_pair(2,j));
                swap(b[j], b[j+1]);
            }
        }
        if(!found) break;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            ans.push_back(make_pair(3,i));
            swap(a[i],b[i]);
        }
    }
    assert(ans.size() <= 1709);
    cout << ans.size() << nl;
    for(auto &[x,y] : ans) {
        cout << x << " " << y + 1 << nl;
    }

    cout << nl;
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

