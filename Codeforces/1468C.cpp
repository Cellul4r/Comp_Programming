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
const int N =5e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
set<int> a; 
set<pi> b;
vector<int> mm;
void solve(){
    
    int type;
    cin>>type;
    if(type == 1) {
        int m; cin>>m;
        mm.push_back(m);
        a.insert(mm.size() - 1);
        b.insert(make_pair(-m, mm.size() - 1));
    } else if(type == 2) {
        int i = *a.begin();
        a.erase(a.begin());
        b.erase(make_pair(-mm[i], i));
        cout << i + 1 << " ";
    } else {
        int i = (*b.begin()).second;
        a.erase(i);
        b.erase(b.begin());
        cout << i + 1 << " ";
    }
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

