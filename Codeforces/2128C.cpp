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
    
    // what does it want?
    // it want for each index i you must sum up to a[i]( from zero)
    // suppose that time index i has value b[i] if i want to add b[i] to a[i]
    // how can I do? b[i] + x = a[i], x <= b[j] (0 <= j < i) and x > b[i]
    // if x <= b[i] increase x , x > b[j] partition x to some small x1,x2,x3 value
    // what position i should we sum up first?
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int now = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < now) {
            now = a[i];
            continue;
        }
        if(a[i] >= 2 * now) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES";
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

