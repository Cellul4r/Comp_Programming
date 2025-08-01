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
const int N =3e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,a[N];
int LOG = 1e6+1;
bool check(vector<int> bits) {
    int bit = 0;
    for(int i = 0; i < LOG; i++) bit += bits[i];
    return (bit == 1);
}
int recur(int i, vector<int> bits) {
    
    //cerr << i << nl;
    if(i == n && check(bits)) {
        /*for(int j = 0; j < 20; j++) {
            cerr << bits[j] << " ";
        }
        cerr << nl;*/
        return 1;
    }
    if(i == n) return 0;
    int ans = 0;
    if(check(bits)) {
        vector<int> nbits(LOG);
        nbits[a[i]]++;
        ans += recur(i+1, nbits);
        ans %= INF;
    }
    bits[a[i]]++;
    for(int j = 0; j < LOG; j++) {
        if(bits[j] == 2) {
            bits[j] = 0;
            bits[j+1]++;
        } else if(bits[j] == 3) {
            bits[j] = 1;
            bits[j+1]++;
        }
    }
    ans += recur(i+1, bits);
    ans %= INF;
    return ans;
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> bits(LOG);
    int ans = recur(0,bits);
    cerr << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

