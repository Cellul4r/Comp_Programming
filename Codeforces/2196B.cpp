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
    
    // ai*aj = j - i
    // then j > i
    // if i == j -> ai*aj = 0 which is impossible

    // ai*aj = j - i
    // min value for j - i is 1
    // max value for j - i is n - 1
    // thus n is maximum of 200000
    // ai * aj <= n <= 200000 
    // ai * aj = 1
    // ai * aj = 2
    // ai * aj = 3
    // ai * aj = 4
    // and so on...

    // aassume we choose ai in the array then we need to find all aj
    // such that ai*aj = j - i
    // ai * aj = 1 -> aj = 1
    // ai * aj = 2 -> ai = 2 / aj
    // aj / aj, 2*aj / aj, 3*aj / aj, ..., (n - 1) * aj / aj
    // (j - i) / aj
    // (j - i) / ai     

    // ai = (j - i) / aj
    // aj = 1
    // aj-1 = 1
    // aj-2 = 2
    // aj-3 = 3
    // aj-4 = 4
    // aj-5 = 5
    // ...
    // aj = 2
    // aj-1 = nope
    // aj-2 = 1
    // aj-4 = 2
    // aj-6 = 3
    // aj-8 = 4
    // aj-10 = 5
    // j - ki >= 1
    // k <= (j-1) / i
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    // we iterate for each j
    // and for each i = j - a[i] * k >= 1, k >= 1
    // this is too slow for small a[i]
    // let B = sqrt(n)
    // split into 2 cases a[i] < B and a[i] >= B
    // we can iterate for a[i] >= B in O(B)

    // proof
    // a[i] * k >= B * k
    // j - a[i] * k <= j - B * k
    // k is at most B thus O(B)
    int B = sqrt(n);

    // for a[i] < B
    // how can we iterate fastly in O(B)?
    // k < B?
    // then j - a[i] * k > j - a[i] * B
    //  > j - B through j - (B - 1) * B

    // j = i + a[i] * k
    // i = j - a[i] * k
    ll ans = 0;
    for(int j = 1; j <= n; j++) {
        if(a[j] >= B) {
            // large value at j match with all small,big value i < j
            for(int i = j - a[j]; i >= 1; i -= a[j]) {
                if((j - i) == 1ll * a[i] * a[j]) {
                    ans++;
                }
            }
            for(int i = j + a[j]; i <= n; i += a[j]) {
                if(a[i] < B && (i - j) == 1ll * a[i] * a[j]) {
                    ans++;
                }
            }
        } else {
            for(int i = j - a[j]; i >= 1 && (j - i) / a[j] < B; i -= a[j]) {
                if((j-i) == 1ll * a[i] * a[j]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << nl;
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

