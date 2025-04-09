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

bool check(vector<int>& cnt) {
    if(cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1) {
        return true;
    }
    return false;
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<int> cnt(10);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        ans++;
        if(check(cnt)) {
            break;
        }
    }
    if(!check(cnt)) {
        cout << 0 << nl;
        return;
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

