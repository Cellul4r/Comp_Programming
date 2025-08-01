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

int n,m,k;
bool check(vector<int>& ord, vector<int> reserved) {

    vector<int> cows(n,-1);
    for(int i = 0; i < n; i++) {
        if(reserved[i] != -1) cows[reserved[i]] = i;
    }
    int now = 0;
    for(int i = 0; i < n && now < m; i++) {
        int x = ord[now];
        if(cows[x] != -1) {
            if(i > cows[x]) return false;

            i = cows[x];
            now++;
        } else {
            while(i < n && reserved[i] != -1) {
                i++;
            }
            if(i == n) return false;

            reserved[i] = x;
            cows[x] = i;
            now++;
        }
    }
    return true;
}
void solve(){
    
    cin>>n>>m>>k;
    vector<int> ord(m);
    // if in k cows there are cow 1, then cow 1 must be in that position
    // if not -> reserve for others k cows
    for(int i = 0; i < m; i++) {
        cin>>ord[i];
        ord[i]--;
    }

    vector<int> cows(n,-1);
    vector<int> reserved(n, -1);
    for(int i = 0; i < k; i++) {
        int c,p;
        cin>>c>>p;
        c--;
        p--;
        cows[c] = p;
        reserved[p] = c;
    }

    if(cows[0] != -1) {
        cout << cows[0] << nl;
        return;
    }
    
    // we try to put cow 1 to this position
    for(int i = 0; i < n; i++) {
        // if cow 1 is in among m cow such that has social hierachy we must validate it carefully.
        if(reserved[i] != -1) continue; 
        reserved[i] = 0;
        //cerr << i << " " << now << nl;
        if(check(ord,reserved)) {
            cout << i + 1 << nl;
            return;
        }
        reserved[i] = -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

