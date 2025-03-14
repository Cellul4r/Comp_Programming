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

ll check(ll m, vector<ll>& a) {
    ll k = 0;
    for(auto &x : a) {
        k += (x + m - 1) / m;
        if(x % m != 0) k++;
    }
    return k;
}
void solve(){
    
    int n;
    cin>>n;

    vector<ll> a(n);
    map<ll,int> save;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        save[a[i]]++;
    }
    sort(all(a));
    /*for(int i = 0; i < n; i++) {
        cerr << a[i] << " ";
    }
    cerr << nl;*/
    vector<pi> b;
    for(auto &x : save) {
        if(x.second == 1) continue;
        b.push_back(make_pair(x.first,x.second));
    }
    if(b.size() == 0) b.push_back(make_pair(a[n-1],1));
    auto comp = [&](int i, int j) {
        if(b[i].second != b[j].second) {
            return b[i].second < b[j].second;
        } else {
            return b[i].first < b[j].first;
        }
    };
    int m = b.size();
    vector<int> c(m);
    for(int i = 0; i < m; i++) c[i] = i;
    sort(all(c), comp);
    /*for(int i = 0; i < m; i++) {
        cerr << c[i] << " ";
    }*/
    //cerr << nl;
    ll ans = INF;
    ans = min(ans, check(a[0], a));
    ans = min(ans, check(a[n/2], a));
    ans = min(ans, check(a[n-1], a));
    /*for(ll j = k; j <= a[n-1]; j += k) {
        ans = min(ans,check(j, a));
    }*/
    for(int i = 0 ; i < min(m,7); i++) {
        if(b[c[i]].second == 1) break;
        ans = min(ans, check(b[c[i]].first, a));
    }
    int l = 0, r = m - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        ll k = check(b[c[mid]].first, a);
        if(k >= ans) {
            l = mid + 1;
        } else {
            ans = k;
            r = mid - 1;
        }
    }
    l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        ll k = check(a[mid], a);
        if(k >= ans) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    for(ll m = 1; m <= a[n-1]; m++) {
        cerr << "CHECK with " << m << " : " << check(m, a) << nl;
    }
    cout << ans << nl;
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

