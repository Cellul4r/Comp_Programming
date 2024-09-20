#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e9;
const ll mod = 1e12+7;

void solve() {
 
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    if((p1 + p2 + p3) % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for(int i=0;i<=p1;++i) {
        for(int j=0;j<=p2;++j) {
            for(int k=0;k<=p1;++k) {
                if(i+k <= p1 && (p1 - i - k) % 2 == 0 &&
                   i+j <= p2 && (p2 - i - j) % 2 == 0 &&
                   j+k <= p3 && (p3 - j - k) % 2 == 0) {
                        ans = max(i+j+k,ans);
                }
            }
        }
    }

    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    //sf("%d",&t); 
    while(t--) {
        solve();
    }
    return 0;
}
/*
10 10
.O......O.
O.....O...
O..O..O.OO
..OOOOOOOO
..........
......O...
..........
..........
..........
O.....OO..
 */
