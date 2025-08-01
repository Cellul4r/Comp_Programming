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

int n;
string name[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", 
                "Bella", "Blue", "Betsy", "Sue"};

int conv(string s) {

    for(int i = 0; i < 8; i++) {
        if(s == name[i]) {
            return i;
        }
    }
    return -1;
}
string conv2(int i) {
    return name[i];
}
vector<int> adj[8];
vector<int> ans;
bool vvis[8];
void solve(){
    
    sort(name,name+8);
    cin>>n;
    for(int i = 0; i < n; i++) {
        string a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        adj[conv(a)].push_back(conv(f));
        adj[conv(f)].push_back(conv(a));
    }

    for(int i = 0; i < 8; i++) {
        if(!vvis[i] && (int)adj[i].size() <= 1) {
            vvis[i] = true;
            ans.push_back(i);
            if((int)adj[i].size() == 1) {
                int k = adj[i][0];
                int prev_ = i;
                vvis[k] = true;
                while((int)adj[k].size() == 2) {
                    vvis[k] = true;
                    ans.push_back(k);

                    int tmp = (prev_ == adj[k][0] ? adj[k][1] : adj[k][0]); 
                    prev_ = k;
                    k = tmp;
                }
                vvis[k] = true;
                ans.push_back(k);
            }
        }
    }
    
    for(auto &x : ans) {
        cout << conv2(x) << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

