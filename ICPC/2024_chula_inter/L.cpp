#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

void solve() {
    
    string k;
    cin>>k;
    int n = k.size();
    int q;
    cin>>q;
    while(q--) {
        string t;
        cin>>t;
        int len = t.length();
        vector<int> save;
        for(int i=0;i<n;++i) {
            if(k[i] == t[0]) save.push_back(i);
        }
        int ans = INF;
        for(auto x:save) {
            int idx = 1,i=x+1;
            int cut = 0;
            while(idx < len && i < n) {
                if(t[idx] == k[i]) {
                    ++idx;
                } else {
                    ++cut;
                }
                ++i;
            }
            if(idx == len) ans = min(ans,cut);
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

