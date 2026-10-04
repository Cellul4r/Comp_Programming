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
    
    string s;
    cin>>s;
    int k; cin>>k;
    // split into 3 segment xxxxx, 0000..., yyyy... -> x != 0, y != 0
    // try to remove first segment as much as possible
    int i = 0;
    int n = s.size();
    vector<array<int,2>> a,b,c;
    vector<bool> vis(n, false);
    for(; i < n && s[i] != '0'; i++) {
        a.push_back({s[i]-'0',i});
    }
    for(; i < n && s[i] == '0'; i++) {
        b.push_back({s[i]-'0',i});
    }
    for(; i < n; i++) {
        c.push_back({s[i]-'0',i});
    }

    // 112118999, k = 4
    // 9:1, 8:2, 7:1
    // 6683749412800000....
    // remove first segment, we want minimum lexicographically smallest string
    // first segment alway have atleast size >= 1
    if(a.size() + b.size() + c.size() - 1 <= (long unsigned int)k) {
        for(auto &x : a) {
            k--;
            vis[x[1]] = true;
        }
    } else {
        int idx = 0;
        int mn = INF;
        for(int i = 0; i < min(k+1,(int)a.size()); i++) {
            if(a[i][0] < mn) {
                idx = i;
                mn = a[i][0];
            }
        }
        k -= idx;
        for(int i = 0; i < idx; i++) {
            vis[a[i][1]] = true;
        }
        for(int i = idx + 1; i < (int)a.size() && k > 0; i++) {
            if(i + 1 == (int)a.size() || a[i][0] >= a[i+1][0]) {
                k--;
                vis[a[i][1]] = true;
            }
        }
    }
    // remove third segment
    if((int)c.size() <= k) {
        for(auto &x : c) {
            k--;
            vis[x[1]] = true;
        }
    } else {
        int idx = 0;
        int mn = INF;
        for(int i = 0; i < min(k+1,(int)c.size()); i++) {
            if(c[i][0] < mn) {
                idx = i;
                mn = c[i][0];
            }
        }
        if(mn != INF) {
            k -= idx;
            for(int i = 0; i < idx; i++) {
                vis[c[i][1]] = true;
            }
            for(int i = idx + 1; i < (int)c.size() && k > 0; i++) {
                if(i + 1 == (int)c.size() || c[i][0] >= c[i+1][0]) {
                    k--;
                    vis[c[i][1]] = true;
                }
            }
        }
    }
    for(int i = 0; i < (int)b.size() && k > 0; i++) {
        vis[b[i][1]] = true;
        k--;
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cout << s[i];
        }
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

