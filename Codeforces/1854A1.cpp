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

    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<pi> ans;
    bool pos = false;
    for(auto &x : a) if(x > 0) pos = true;
    if(!pos) {
        for(int i = n - 2; i >= 0; i--) {
            while(a[i] > a[i+1]) {
                ans.push_back(make_pair(i,i+1));
                a[i] += a[i+1];
            }
        }
    } else {
        int max_ = 0, id = -1;
        for(int i = 0; i < n; i++) {
            if(max_ < a[i]) {
                max_ = a[i];
                id = i;
            }
        }
        for(int i = 0; i < 5; i++) {
            ans.push_back(make_pair(id,id));
            a[id] += a[id];
        }
        max_ = a[id];
        for(int i = 1; i < n; i++) {
            while(a[i] < max_) {
                ans.push_back(make_pair(i,id));
                a[i] += max_;
            }
            id = i;
            max_ = a[i];
        }
    }
    /*for(int i = 0; i < n; i++) cerr << a[i] << " ";
    cerr << nl;*/
    assert((int)ans.size() <= 50);
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << nl;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

