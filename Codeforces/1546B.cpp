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
    
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    vector<vector<int>> cnt1(m, vector<int>(26)), cnt2(m, vector<int>(26));
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        for(int j = 0; j < m; j++) {
            cnt1[j][a[i][j]-'a']++;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            cnt2[j][s[j]-'a']++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = 0; j < m; j++) {
            if(cnt1[j][a[i][j]-'a'] - 1 != cnt2[j][a[i][j]-'a']) {
                flag = true;
            }
        }
        if(!flag) {
            cout << a[i] << endl;
            return;
        }
    }

    assert(false);
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

