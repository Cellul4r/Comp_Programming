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
    
    int n; cin>>n;

    vector<int> a(n+1);
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        s += a[i];
    }
    if(s % n != 0) {
        cout << "NO\n";
        return;
    }
    s /= n;
    // find how much we need to give and how much we need to get back
    vector<int> want(33), give(33);
    for(int i = 1; i <= n; i++) {
        int k = a[i] - s;
        if(k == 0) {
            continue;
        }
        vector<int> cur;
        for(int j = 0; j < 31; j++) {
            if((1<<j) & abs(k)) {
                cur.push_back(j);
            }
        }
        for(int j = 1; j < (int)cur.size(); j++) {
            if(cur[j] - 1 != cur[j-1]) {
                cout << "NO\n";
                return;
            }
        }
        assert(!cur.empty());
        int l = cur[0], r = cur.back();
        if(k > 0) {
            // a[i] > s
            want[l]++;
            give[r+1]++;
        } else {
            // a[i] < s
            want[r+1]++;
            give[l]++;
        }
    }
    // we can start with anybody who can give their amount to others such that they have enough candies to give, since it is a cycle!
    for(int i = 0; i <= 32; i++) {
        if(want[i] != give[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

