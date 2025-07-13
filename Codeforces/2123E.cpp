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
    vector<int> a(n);
    vector<int> freq(n+1);
    for(auto &x : a) {
        cin>>x;
        freq[x]++;
    }
    vector<int> ans(n+2);
    int sum = n, pre = 0;
    for(int i = 0; i <= n; i++) {
        int l = freq[i], r; 
        r = sum + pre - i; 
        //cerr << l << " " << r << nl;
        if(l <= r) {
            ans[l]++;
            ans[r+1]--;
        }
        sum -= freq[i];
        pre += freq[i];
        if(freq[i] == 0) break;
    }
    for(int i = 1; i <= n + 1; i++) {
        ans[i] += ans[i-1];
    }
    for(int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
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

