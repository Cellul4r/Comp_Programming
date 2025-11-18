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
bool recur(int i, int& len, string now, string& ans, set<string>& save) {
    if(i == len) {
        if(save.count(now) == 0) {
            ans = now; 
            return true;
        }
        return false;
    }

    for(int j = 0; j < 26; j++) {
        now.push_back(j+'a');
        if(recur(i+1,len,now,ans,save)) {
            return true;
        }
        now.pop_back();
    }

    return false;
}
void solve(){
    
    int n;
    string s;
    cin>>n>>s;
    set<string> save;
    for(int len = 1; len <= 3; len++) {
        for(int i = 0; i < n - len + 1; i++) {
            save.insert(s.substr(i,len));
        }
    }

    string ans;
    for(int len = 1; len <= 3; len++) {
        if(recur(0,len,"",ans,save)) {
            break;
        }
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

