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

void solve(){
    
    int n;
    string a,b;
    cin>>n>>a>>b;

    string s1,t1;
    s1 = a;
    t1 = b;
    sort(all(s1));
    sort(all(t1));
    if(s1 != t1) {
        cout << "NO" << nl;
        return;
    }
    s1.clear();
    t1.clear();
    vector<int> idx1, idx2;
    for(int i = 0; i < n; i++) {
        if(a[i] != 'b') {
            s1 += a[i];
            idx1.push_back(i);
        }
        if(b[i] != 'b') {
            t1 += b[i];
            idx2.push_back(i);
        }
    }

    if(s1 != t1) {
        cout << "NO" << nl;
        return;
    }

    for(int i = 0; i < (int)idx1.size(); i++) {
        if(s1[i] == 'a' ? (idx1[i] > idx2[i]) : (idx1[i] < idx2[i])) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
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

    cin>>t;
    while(t--)solve();

    return 0;
}

