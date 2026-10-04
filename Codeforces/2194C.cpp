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
    
    int n,k; cin>>n>>k;
    vector<vector<bool>> a(n, vector<bool>(26, false));
    vector<string> ss(k);
    for(int i = 0; i < k; i++) {
        string s; cin>>s;
        ss[i] = s;
        for(int j = 0; j < n; j++) {
            a[j][s[j] - 'a'] = true;
        }
    }

    vector<int> divi;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            divi.push_back(i);
        }
    }
    string t;
    for(auto &mid : divi) {
        bool ok = true;
        string cur;
        for(int i = 0; i < mid; i++) {
            bool found = false;
            for(int j = 0; j < k; j++) {
                bool flag = true;
                for(int x = i + mid; x < n; x += mid) {
                    if(!a[x][ss[j][i] - 'a']) {
                        flag = false;     
                        break;
                    }
                }
                if(flag) {
                    cur += ss[j][i];
                    found = true;
                    break;
                }
            }
            if(!found) {
                ok = false;
                break;
            }
        }
        if(ok) {
            t = cur;
            break;
        }
    }
    string ans;
    while((int)ans.size() != n) {
        ans += t;
    }
    cout << ans << nl;
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

