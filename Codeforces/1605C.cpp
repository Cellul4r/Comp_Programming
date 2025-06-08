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
    string s;
    cin>>n>>s;
    vector<int> a(n+1), b(n+1), c(n+1), idx;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            a[i+1]++;
            idx.push_back(i+1);
        } else if(s[i] == 'b') {
            b[i+1]++;
        } else {
            c[i+1]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        c[i] += c[i-1];
    }
    
    int l = 0, r = idx.size() - 1;
    int ans = INF;
    while(l < r) {
        //cerr << l << " " << r << nl;
        int ll = idx[l];
        int rr = idx[r];
        int aa = a[rr] - a[ll-1];
        int bb = b[rr] - b[ll-1];
        int cc = c[rr] - c[ll-1];
        if(aa > bb && aa > cc) {
            ans = min(ans, rr - ll + 1);
        }
        // l++ or r-- ?
        int diffL = (l + 1 < (int)idx.size() ? idx[l+1] - ll : 0);
        int diffR = (r - 1 >= 0 ? rr - idx[r-1] : 0);
        if(diffL > diffR) {
            l++;
        } else if(diffL < diffR){
            r--;
        } else if(aa <= bb && b[diffL+ll] - b[ll-1] > b[rr] - b[rr - diffR - 1]) {
            l++;
        } else if(aa <= cc && c[diffL+ll] - c[ll-1] > c[rr] - c[rr - diffR - 1]) {
            l++;
        } else {
            r--;
        }
    }
    cout << (ans == INF ? -1 : ans) << nl;
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

