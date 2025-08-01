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
string s;
void solve(){
    
    cin>>n;
    cin>>s;

    int flip = 0;
    for(int i = n - 2; i >= 0; i -= 2) {
        // we found that at odd position ie. at index even
        // if we want to change them we need to flip adjacent letter to the right also
        // because need even length prefix
        // then there only possible 4 ways 'GG' 'HH' 'GH' 'HG'
        // we only flip GH and HG 
        // case 1 if we never flip or flip even times
        // then GH is not good 
        // case 2 if we flip odd times
        // then HG is not good because after flip odd times it becomes GH -> bad from case 1
        if(s[i] == 'G' && s[i+1] == 'H' && flip % 2 == 0) {
            flip++;
        } else if(s[i] == 'H' && s[i+1] == 'G' && flip % 2 == 1) {
            flip++;
        }
    }
    cout << flip;
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

