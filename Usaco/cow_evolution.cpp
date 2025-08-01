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
map<string, vector<int>> save;
vector<string> features;
void solve(){

    cin>>n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin>>k;
        for(int j = 0; j < k; j++) {
            string s;
            cin>>s;
            save[s].push_back(i);
            if(find(all(features), s) == features.end()) {
                features.push_back(s);
            }
        }
    }

    int m = features.size();
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            int one1 = 0, one2 = 0, two = 0;
            vector<int>& a = save[features[i]];
            vector<int>& b = save[features[j]];
            for(auto &x : a) {
                if(find(all(b), x) == b.end()) {
                    one1++;
                } else {
                    two++;
                }
            }
            for(auto &x : b) {
                if(find(all(a), x) == a.end()) {
                    one2++;
                }
            }
            if(two > 0 && one1 > 0 && one2 > 0) {
                //cerr << i << " " << j << nl;
                cout << "no";
                return;
            }
        }
    }

    cout << "yes";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

