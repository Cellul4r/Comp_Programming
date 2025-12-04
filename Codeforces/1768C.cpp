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
    vector<vector<int>> p(n+1);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        p[a[i]].push_back(i);
    }
    bool ok = true;
    vector<int> b(n), c(n);
    if(p[n].empty()) ok = false;
    for(int i = 1; i <= n; i++) {
        if((int)p[i].size() > 2) {
            ok = false;
        }
    }
    vector<int> cur;
    for(int i = n; i >= 1; i--) {
        int k = p[i].size();
        if(k == 0) {
            if((int)cur.size() < 2) {
                ok = false;
                break;
            }
            if(b[cur.back()] == 0) {
                b[cur.back()] = i;
            } else {
                c[cur.back()] = i;
            }
            cur.pop_back();
            if(b[cur.back()] == 0) {
                b[cur.back()] = i;
            } else {
                c[cur.back()] = i;
            }
            cur.pop_back();
        } else if(k == 1) {
            b[p[i][0]] = c[p[i][0]] = i; 
        } else {
            b[p[i][0]] = i;
            c[p[i][1]] = i;
            cur.push_back(p[i][0]);
            cur.push_back(p[i][1]);
        }
    }
    if(!ok) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    for(auto &x : b) {
        cout << x << " ";
    }
    cout << nl;
    for(auto &x : c) {
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

