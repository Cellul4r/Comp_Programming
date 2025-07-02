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
    
    int n,j,k;
    cin>>n>>j>>k;
    j--;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int cnt = 0, val = a[j];
    sort(all(a));
    bool equal = false;
    if(val == a[n-1]) {
        cout << "Yes" << nl;
        return;
    }
    for(int i = 0; i < n - 1 && cnt < n - k; i++) {
        if(a[i] == val && !equal) {
            equal = true;
            continue;
        }
        cnt++;
    }
    if(cnt == n - k) {
        cout << "Yes" << nl;
    } else {
        cout << "No" << nl;
    }
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

