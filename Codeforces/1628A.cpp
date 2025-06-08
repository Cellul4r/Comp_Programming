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
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<int> ans;
    vector<int> suff(n+1,-1), cnt(n+3);
    int mex = 0;
    for(int i = n - 1; i >= 0; i--) {
        cnt[a[i]]++;
        while(cnt[mex]) {
            mex++;
        }
        suff[i] = mex;
        //cerr << suff[i] << " ";
    }
    //cerr << nl;
    int l = 0;
    while(l < n) {
        // mex(l,r) = mex(l,n)
        int r = l;
        mex = 0;
        vector<bool> found(n+3);
        while(r < n) {
            found[a[r]] = true;   
            while(found[mex]) {
                mex++;
            }
            if(mex == suff[l]) break;
            //cerr << mex << " " << r << nl;
            r++;
        }
        //cerr << l << " " << r << nl;
        ans.push_back(mex);
        l = r + 1;
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
    }
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

