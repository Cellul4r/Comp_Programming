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
typedef unsigned int uint;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    vector<int> brown(3), green(3), clr(3);
    while(cin>>brown[0]) {
        int b=0,g=0,c=0;
        uint ans = UINT_MAX;
        string now = "ZZZ";
        b += brown[0];
        for(int i = 1; i < 9; i++) {
            if(i % 3 == 0) {
                cin>>brown[i / 3];
                b += brown[i / 3];
            } else if(i % 3 == 1) {
                cin>>green[i / 3];
                g += green[i / 3];
            } else {
                cin>>clr[i / 3];
                c += clr[i / 3];
            }
        }
        //cout << b << " " << g << " " << c << endl;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(j == k) continue;
                int l = 3 - j - k;
                string cur = "ZZZ";
                uint check = 0;
                for(int x = 0; x < 3; x++) {
                    if(x == j) {
                        cur[x] = 'B';
                        check += b - brown[x];
                    }

                }
                for(int x = 0; x < 3; x++) {
                    if(x == k) {
                        cur[x] = 'G';
                        check += g - green[x];
                    }
                }
                for(int x = 0; x < 3; x++) {
                    if(x == l) {
                        cur[x] = 'C';
                        check += c - clr[x];
                    }
                }
                //cout << check << " " << cur << endl;
                if(check < ans) {
                    ans = check;
                    now = cur;
                } else if(check == ans && cur < now) {
                    now = cur;
                }
            }
        }
        cout << now << " " << ans << nl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

