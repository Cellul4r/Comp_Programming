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
int a;
ll n;
int bits;
bool palin(string val, int firstIdx) {
    int l = firstIdx, r = val.length() - 1;
    while(l < r) {
        if(val[l] != val[r]) {
            return false;
        }
        l++,r--;
    }
    return true;
}

bool palinInt(ll val) {
    ll tmp = val;
    ll rev = 0;
    while(tmp > 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == val;
}
ll check(string val) {
    int firstIdx = -1;
    for(int i = 0; i < bits; i++) {
        if(val[i] != '0') {
            firstIdx = i;
            break;
        }
    }
    if(firstIdx == -1) return false;  
    if(!palin(val, firstIdx)) return false;
    ll ans = 0, pow = 1;
    for(int i = bits - 1; i >= firstIdx; i--, pow *= a) {
        ans += pow * (val[i] - '0'); 
    }
    return (palinInt(ans) && ans <= n ? ans : -1ll);
}
ll recur(int i, string val) {
    if(i == bits) {
        cerr << val << endl;
        ll ans = check(val);
        if(check(val) != -1) {
            return ans;
        }
        return 0;
    }
    ll ans = 0;
    for(int j = 0; j < a; j++) {
        val += j + '0';
        ans += recur(i+1, val); 
        val.pop_back();
    }
    return ans;
}
void solve(){
    
    cin>>a>>n;
    bits = ceil(log(n) / log(a));
    cerr << bits << nl;
    ll ans = recur(0, "");
    cout << ans; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

