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
    
    int n,k;
    cin>>n>>k;
    int ones = 0;
    string s;
    cin>>s;
    for(auto &x : s) {
        if(x == '1') ones++;
    }
    if(k >= ones) {
        cout << "Alice" << nl;
        return;
    }
    if(k == 1) {
        cout << "Bob" << nl;
        return;
    }

    // k = 2, 3, ... , n
    int cnt = 0;
    for(int i = 0; i < k && cnt < k; i++) {
        for(int j = i; j < n && cnt < k; j += k) {
            if(s[j] == '0') continue;
            s[j] = '0';
            cnt++;
        }
    }
    int mxZ = 0;
    for(int i = 0; i < n; i++) {
        // zeros
        if(s[i] == '1') continue;
        int j = i;
        int zero = 0;
        while(j < n && s[j] == '0') {
            zero++;
            j++;
        }
        mxZ = max(mxZ, zero);
        i = j - 1;
    }
    for(int i = 0; i < n; i++) {
        // zeros
        if(s[i] == '1') continue;
        int j = i;
        int zero = 0;
        while(j < n && s[j] == '0') {
            zero++;
            j++;
        }
        if(zero == mxZ) {
            for(int k = i; k < j; k++) {
                s[k] = '1';
            }
            break;
        }
        i = j - 1;
    }
    ones = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ones++;
        }
    }

    cout << (ones <= k ? "Alice" : "Bob") << nl;
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

