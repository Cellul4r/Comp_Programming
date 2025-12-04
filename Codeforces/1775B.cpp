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

    int n; cin>>n;
    // find i such that number of i is subset of number of position j
    // then first subseq = j
    // and second subseq = i + j
    // if we find this exist -> YES
    // otherwise NO
    // how do we find it???
    vector<vector<int>> a(n);
    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        a[i].resize(k);
        for(auto &x : a[i]) {
            cin>>x;
            cnt[x]++;
        }
    }
     
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(auto &x : a[i]) {
            if(cnt[x] == 1) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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

