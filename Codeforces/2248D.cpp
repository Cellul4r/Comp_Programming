/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,q; cin>>n>>q;
    string a,b; cin>>a>>b;
    vector<int> preA(n+1,0), preB(n+1, 0);
    // preA (0,1) preB (1,0)
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            if(a[i] == '0') preA[i+1] = 1;
            else preB[i+1] = 1;
        }
        preA[i+1] += preA[i];
        preB[i+1] += preB[i];
    }
    for(int i = 1; i <= q; i++) {
        int l,r; cin>>l>>r;
        int cur = r - l + 1;
        int diffA = preA[r] - preA[l-1];
        int diffB = preB[r] - preB[l-1];
        int same = cur - diffA - diffB;
        int k = min(diffA, diffB);
        diffA -= k;
        diffB -= k;
        if(diffA > 0) {
            k = min(diffA, same);
            same -= k;
            diffA -= k;
        } else if(diffB > 0) {
            k = min(diffB, same);
            same -= k;
            diffB -= k;
        }
        cout << (diffA == 0 && diffB == 0 ? "YES" : "NO") << nl;
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

