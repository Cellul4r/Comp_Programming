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
    
    int n,k; cin>>n>>k;
    vector<int> a(27), b(27);
    string s,t; cin>>s>>t;
    for(auto &x : s) {
        a[x-'a']++;
    }
    for(auto &x : t) {
        b[x-'a']++;
    }

    int cur = 0;
    bool flag = true;
    for(int i = 0; i < 26;) {
        if(b[i] == 0) {
            i++;
            continue;
        }
        while(a[cur] == 0 && cur < 26) {
            cur++;
        }
        if(i < cur) {
            flag = false;
            break;
        }
        if(i == cur) {
            a[cur]--;
            b[i]--;
        } else if(a[cur] % k != 0){
            flag = false;
            break;
        } else {
            a[cur+1] += a[cur];
            a[cur] = 0;
            ++cur;
        }
    }
    cout << (flag ? "YES" : "NO") << nl;
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

