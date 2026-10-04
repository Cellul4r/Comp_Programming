/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ans; cin>>ans;
    return ans;
}
void answer(int r, int c) {
    cout << "! " << r << " " << c << endl;
}

void solve(){

    int n,m; cin>>n>>m;
    // ask(1,1) -> a
    // ask(n,1) -> b
    // if a = b -> we know that 
    int a = ask(1,1);
    int b = ask(n,1);

    if(a + b == n - 1) {
        // c <= r, c + r <= n + 1
        int r = a + 1;
        int c = ask(r, 1) + 1;
        answer(r,c);
    } else {
        if(a == b) {
            int c = a + 1; 
            int r = ask(1, c) + 1;
            answer(r,c);
        } else {
            int r = a + 1;
            int c = b + 1;
            if(r < c) {
                r = n - b;
                c = a + 1;
            }
            answer(r,c);
        }
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

