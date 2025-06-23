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
    ll c,d;
    cin>>n>>c>>d;
    vector<int> a;
    ll ans = 0;
    set<int> save;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(save.count(x)) {
            ans += c;
            continue;
        }
        save.insert(x);
        a.push_back(x);
    }

    int k = a.size();
    ll test = c * n + d;
    sort(all(a));
    int now = 0;
    for(int i = 0; i < k; i++) {
        int& x = a[i];    
        //cerr << x << nl;
        now++;
        test = min(test, ans + c * (k - i - 1) + d * (x - now));
    }
    cout << test << nl;
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

