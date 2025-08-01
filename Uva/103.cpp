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

struct p {
    int id;
    vector<int> a;
    
    p(int id, vector<int> a) {
        this->id = id;
        this->a = a;
    }

    bool operator<(const p& rhs) const {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(a[i] < rhs.a[i]) return true;
            if(a[i] > rhs.a[i]) return false;
        }

        return true;
    }
};

bool check(vector<p>& boxs, int i, int j) {
    // i is nested in j ?
    int n = boxs[0].a.size();
    for(int k = 0; k < n; k++) {
        if(boxs[i].a[k] >= boxs[j].a[k]) return false;
    }
    return true;
}
void solve(){

    int k,n;    
    while(cin>>k>>n) {
        vector<p> boxs;
        vector<int> a(n);
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++) {
                cin>>a[j];
            }
            sort(all(a));
            boxs.push_back(p(i,a));
        }
        sort(all(boxs));
        // dp LIS longest increasing subsequence
        vector<int> dp(k, 1), par(k, -1);
        int maxLen = 1, idx = 0;
        for(int i = 0; i < k; i++) {
            // start at box i
            for(int j = 0; j < i; j++) {
                if(check(boxs, j, i) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                idx = i;
            }
        }
        cout << maxLen << nl;
        vector<int> ans;
        while(idx != -1) {
            ans.push_back(idx);
            idx = par[idx];
        }
        reverse(all(ans));
        for(auto &x : ans) {
            cout << boxs[x].id + 1 << " ";
        }
        cout << nl;
    }
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

