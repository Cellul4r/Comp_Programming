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
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

void solve() {
    
    map<int,string> save;
    save[2] = "abc";
    save[3] = "def";
    save[4] = "ghi";
    save[5] = "jkl";
    save[6] = "mno";
    save[7] = "pqrs";
    save[8] = "tuv";
    save[9] = "wxyz";

    string k;
    cin>>k;
    int n = k.length();
    int i = n-1;
    string ans;
    while(i >= 0) {
        int val = k[i] - '0';
        int j = i;
        int cnt = 0, sz = (val == 7 || val == 9 ? 4 : 3);
        while(j >= 0 && cnt < sz && k[i] == k[j]) {
            ++cnt;
            --j;
        }
        ans += save[val][(cnt - 1) % sz];
        i = j;
    }
    reverse(A(ans));
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

