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
const int INF = 1e9+0;
const ll LINF = 1e18+7;

int n,m,k;
vector<int> ans;
bool test(int x) {
    
    vector<int> a(n, -1);
    vector<int> cnt(x);
    for(int i = 0; i <= n - x; i += max(x,k)) {
        for(int j = x - 1, now = 0; j >= 0; j--,now++) {
            a[i+now] = j;
            cnt[j]++;
        }
    }
    for(int i = 0; i < x; i++) {
        if(cnt[i] <= m) {
            return false;
        }
    }
    for(auto &x : a) {
        if(x == -1) x = INF;
    }
    ans = a;
    return true;
}
void solve(){
    
    cin>>n>>m>>k;

    int l = 1, r = 2e5+1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(test(mid)) {
            //cerr << mid << nl;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    for(auto &x : ans) {
        cout << x << " ";
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

