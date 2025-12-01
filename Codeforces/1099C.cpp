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
    
    string s;
    int k;
    cin>>s>>k;
    int n = s.size();
    int cnt = 0;
    int a = 0, b = 0;
    for(auto &x : s) {
        if(x == '?' || x == '*') {
            if(x == '?') a++;
            else b++;
            continue;
        }
        cnt++;
    }
    if(cnt == k) {
        // no need to anything
        for(auto &x : s) {
            if(x == '?' || x == '*') continue;
            cout << x;
        }
    } else if(cnt < k) {
        // must has 1 *
        if(b == 0) {
            cout << "Impossible";
        } else {
            for(int i = 0; i < n; i++) {
                if(s[i] == '?') continue;
                if(s[i] == '*') {
                    while(cnt < k) {
                        cout << s[i-1];
                        cnt++;
                    }
                } else {
                    cout << s[i];
                }
            }
        }
    } else {
        // can we delete it?
        if(a + b < cnt - k) {
            cout << "Impossible";
        } else {
            for(int i = 0; i < n; i++) {
                if(s[i] == '?' || s[i] == '*') continue;
                if(cnt > k && (s[i+1] == '?' || s[i+1] == '*')) {
                    cnt--; 
                } else {
                    cout << s[i];
                }
            }
        }
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

