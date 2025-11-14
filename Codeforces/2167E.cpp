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
    
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));

    auto f = [&](int m) {
        int cnt = 0;
        cnt += max(0,a[0] - m + 1); 
        for(int i = 1; i < n; i++) {
            cnt += max(0, (a[i] - m) - (a[i-1] + m) + 1);
        }
        cnt += max(0,x - (a[n-1] + m) + 1);
        //cerr << m << " " << cnt << nl;
        return cnt >= k;
    };

    int l = 0, r = x;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    vector<int> ans;
    for(int i = 0; i <= a[0] - l && k > 0; i++) {
        ans.push_back(i);
        k--;
    }
    for(int i = a[n-1] + l; i <= x && k > 0; i++) {
        ans.push_back(i);
        k--;
    }

    for(int i = 1; i < n; i++) {
        for(int j = max(a[i-1]+1,a[i-1] + l); j <= a[i] - l && k > 0; j++) {
            ans.push_back(j); 
            k--;
        }
    }
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl << nl;
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

