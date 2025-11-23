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
void solve(){
    
    int n;
    cin>>n;
    vector<array<int,2>> a(n);
    for(int i = 0; i < n; i++) {
        int x,y; cin>>x>>y;
        a[i] = {x,y};
    }
    sort(all(a), [&](array<int,2> i, array<int,2> j) {
                if(i[1] != j[1]) {
                    return i[1] < j[1];
                }
                return i[0] < j[0];
            });
    int curX = 0, curY = 0;
    bool ok = true;
    string s;
    for(int i = 0; i < n; i++) {
        int x = a[i][0], y = a[i][1];
        if(x < curX || y < curY) {
            ok = false;
            break;
        }
        while(curX < x) {
            s += "R";
            curX++;
        }
        while(curY < y) {
            s += "U";
            curY++;
        }
    }

    if(!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << s << nl;
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

