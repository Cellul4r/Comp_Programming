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
bool edge[26][26];
int deg[26];
void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &x : a) cin>>x;
    bool ok = true;
    for(int i = 1; i < n; i++) {
        int j = 0, k = 0;   
        bool found = false;
        while(j < (int)a[i-1].size() && k < (int)a[i].size()) {
            if(a[i-1][j] != a[i][k]) {
                if(!edge[a[i-1][j]-'a'][a[i][k]-'a']) {
                    edge[a[i-1][j]-'a'][a[i][k]-'a'] = 1;
                    deg[a[i][k]-'a']++;
                }
                found = true;
                break;
            }
            j++;
            k++;
        }
        if(!found && a[i-1].size() > a[i].size()) {
            ok = false;
        }
    }

    string ans;
    queue<int> Q;
    for(int i = 0; i < 26; i++) if(deg[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int u = Q.front();
        //cerr << u << nl;
        ans += u + 'a';
        Q.pop();
        for(int i = 0; i < 26; i++) {
            if(edge[u][i]) {
                deg[i]--;
                if(deg[i] == 0) {
                    Q.push(i);
                }
            }
        }
    }
    if(ans.size() < 26) ok = false;
    cout << (ok ? ans : "impossible");
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

