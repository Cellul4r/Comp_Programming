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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,m,h,t,p;
vector<pl> people[N];
bool check(int x, int y) {

    // time x at height y
    if(x < t || y == h) return true;
    if(y < (x - t + 1) * p) {
        return false;
    }
    return true;
}
void solve(){
   
    cin>>n>>m>>h>>t>>p;
    for(int i = 0; i < m; i++) {
        int x,tim,high;
        cin>>x>>tim>>high;
        people[x].push_back(make_pair(tim,high));
    }

    for(int i = 1; i <= n; i++) {
        sort(all(people[i]));
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(people[i].size() == 0) continue;
        if(people[i][people[i].size()-1].second != h) continue;
        ll prevT = people[i][0].first, prevH = people[i][0].second;
        bool ok = true;
        for(int j = 0; j < (int)people[i].size(); j++) {
            if(!check(people[i][j].first - 1, prevH)) {
                //cerr << j << nl;
                ok = false;
                break;
            } else if(!check(people[i][j].first, people[i][j].second)) {
                ok = false;
                //cerr << j << nl;
                break;
            }
            prevT = people[i][j].first, prevH = people[i][j].second;
        }

        if(ok) {
            //cerr <<"HI";
            ans.push_back(i);
        }
    }

    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(tt--)solve();

    return 0;
}

