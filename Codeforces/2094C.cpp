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

void solve(){
    
    int n;
    cin>>n;

    set<int> save;
    for(int i = 0; i < 2*n;i++){
        save.insert(i+1);
    }
    vector<int> ans(2*n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin>>x;
            ans[i+j+1] = x;
            if(save.count(x)) {
                save.erase(x);
            }
        }
    }

    ans[0] = *save.begin();
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

