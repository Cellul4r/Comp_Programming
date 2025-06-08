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
const int INF = 998244353;
const ll LINF = 1e18+7;

void setIO(string);
int pow2[N];
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int max1 = -1, max2 = -1;
    int idx1 = -1, idx2 = -1;
    int ans1 = -1, ans2 = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] > max1) {
            max1 = a[i];
            idx1 = i; 
        }
        if(b[i] > max2) {
            max2 = b[i];
            idx2 = i;
        }
        if(max(a[idx1],b[i-idx1]) > max(a[i-idx2],b[idx2])) {
            ans1 = idx1;
            ans2 = i - idx1;
        } else if(max(a[idx1],b[i-idx1]) < max(a[i-idx2],b[idx2])) {
            ans1 = i - idx2;
            ans2 = idx2;
        } else if(min(a[idx1],b[i-idx1]) > min(a[i-idx2],b[idx2])) {
            ans1 = idx1;
            ans2 = i - idx1;
        } else {
            ans1 = i - idx2;
            ans2 = idx2;
        }
        //cerr << idx1 << " " << idx2 << " " << max1 << " " << max2 << nl;
        cout << (pow2[a[ans1]] + pow2[b[ans2]]) % INF << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow2[i] = pow2[i-1] * 2;
        pow2[i] %= INF;
    }
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

