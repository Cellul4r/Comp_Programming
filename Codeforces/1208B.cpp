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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    auto f = [&](int k) {
        // remove subsegment k value
        multiset<int> save;
        set<int> wow;
        for(int i = 0; i < n; i++) {
            save.insert(a[i]);
            wow.insert(a[i]);
        }
        for(int i = 0; i < k; i++) {
            if(save.count(a[i]) == 1) {
                wow.erase(a[i]);
            }
            save.erase(save.find(a[i]));
        }
        int rem = n - k;
        if((int)wow.size() == rem) {
            //cout << save.size() << " HI\n";
            return true;
        }
        int cur = 0;
        for(int i = k; i < n; i++) {
            save.insert(a[cur]);
            wow.insert(a[cur]);
            if(save.count(a[i]) == 1) {
                wow.erase(a[i]);
            }
            save.erase(save.find(a[i]));
            if((int)wow.size() == rem) return true;
            cur++;
        }
        return false;
    };
    int l = 0, r = n - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        if(f(m)) {
            //cout << m << nl;
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
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

