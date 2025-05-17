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
const int N =1e4+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
vector<int> towers[N];
vector<int> a;
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        int k;
        cin>>k;
        for(int j = 0; j < k; j++) {
            int x;
            cin>>x;
            towers[i+1].push_back(x);
            a.push_back(x);
        }
    }

    int x = 0, y = 0;
    sort(all(a)); 
    for(int i = 1; i <= n; i++) {
        int j = 0;
        while(j < (int)towers[i].size()) {
            int idx = lower_bound(all(a), towers[i][j]) - a.begin();
            j++,idx++;
            while(j < (int)towers[i].size() && towers[i][j] == a[idx]) {
                idx++;
                j++;
            }
            if(j != (int)towers[i].size()) {
                cerr << i << " " << j << " " << towers[i][j] << endl;
                x++;
                n++;
            }
        }
    }
    y = n - 1;
    cout << x << " " << y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

