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
set<int> digit[10];
vector<int> a[10];
int n,d;
void solve(){
    
    cin>>n>>d;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a[x%10].push_back(x);
    }
    for(int i = 0; i <= 9; i++) {
        sort(all(a[i]));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    for(int i = 0; i <= 9; i++) {
        while(digit[i].count(i) == 0) {
            digit[i].insert(i);
            i *= i;
        }
    }
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

