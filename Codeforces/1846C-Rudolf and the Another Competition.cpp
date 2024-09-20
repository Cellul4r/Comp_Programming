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
const int N = 1e6+10;
const int mod = 1e9+7;

struct score {

    ll prob,pain;
    int idx;

    bool operator<(const score& rhs) const {
        if(prob != rhs.prob) {
            return prob > rhs.prob;
        } else if(pain != rhs.pain) {
            return pain < rhs.pain;
        }
        return idx < rhs.idx;
    }
};
void solve() {
    
    int n,m,h;
    cin>>n>>m>>h;
    priority_queue<int, vector<int>, greater<int>> t;
    int ans = 1;
    ll solveMin = 0, pain = 0, prob = 0;
    vector<score> Q;
    for(int i=0;i<n;++i) {
        solveMin = pain = prob = 0;
        for(int j=0;j<m;++j) {
            int k;
            cin>>k;
            t.push(k);
        }
        while(!t.empty()) {
            int k = t.top();
            t.pop();
            if(k + solveMin <= h) {
                ++prob;
                solveMin += k;
                pain += solveMin;
            }
        }
        Q.push_back({prob,pain,i});
    }
    sort(A(Q));
    for(auto x: Q) {
        if(x.idx == 0) {
            cout << ans << endl;
            return;
        }
        ++ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;

    cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

