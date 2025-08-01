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

struct p {
    int weightL = 0, weightR = 0;
    int left = -1,right = -1;
};
int n;
int ans = 0;
vector<p> a;
void solve(){

    cin>>n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        int A,L,B,R;
        cin>>A>>L>>B>>R;
        p now;
        if(A == 0) {
            L--;
            now.left = L;
        } else {
            now.weightL = L;
        }
        if(B == 0) {
            R--;
            now.right = R;
        } else {
            now.weightR = R;
        }
        a[i] = now;
    }

    for(int i = n - 1; i >= 0; i--) {
        p& now = a[i];
        now.weightL = now.left == -1 ? now.weightL : a[now.left].weightL + a[now.left].weightR;
        now.weightR = now.right == -1 ? now.weightR : a[now.right].weightL + a[now.right].weightR;
        int diff = abs(now.weightL - now.weightR);
        if(now.weightL < now.weightR) {
            now.weightL += diff;
        } else {
            now.weightR += diff;
        }
        ans += diff;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

