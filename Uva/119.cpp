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
int n,tmpN;
bool flag = false;
int cnt = 0;
void solve(){
    
    while(true) {
        tmpN = -1;
        if(!flag) {
            cin>>n;
            flag = true;
        }
        vector<string> name(n);        
        vector<long long> price(n);
        for(auto &x : name) cin>>x;
        string cur; 
        while(cin>>cur) {
            int idx = -1;
            long long spent,m;
            for(int i = 0; i < n; i++) {
                if(cur == name[i]) {
                    idx = i;
                    break;
                }
            }
            if(idx == -1) {
                tmpN = stoi(cur);
                break;
            }
            cin>>spent>>m;
            //cout << m << nl;
            if(m > 0) price[idx] -= spent / m * m;
            for(int i = 0; i < m; i++) {
                cin>>cur; 
                idx = -1;
                for(int j = 0; j < n; j++) {
                    if(name[j] == cur) {
                        idx = j;
                        break;
                    }
                }
                price[idx] += spent / m;
            }
        }

        if(cnt++ > 0) cout << nl;
        for(int i = 0; i < n; i++) {
            cout << name[i] << " " << price[i] << nl;
        }
        if(tmpN == -1) break;
        n = tmpN;
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

