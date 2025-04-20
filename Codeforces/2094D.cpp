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

string a,b;
int n,m;
void solve(){
    
    cin>>a>>b;
    n = a.size(), m = b.size();
    vector<int> A,B;
    vector<char> typeA,typeB;
    int i = 0, cnt = 0;
    char type = a[0];
    while(i < n) {
        if(a[i] != type) {
            if(cnt != 0) {
                typeA.push_back(type);
                A.push_back(cnt);
                cnt =  1;
            }
        } else {
            cnt++;
        }
        type = a[i];
        i++;
    }
    if(cnt != 0) {
        typeA.push_back(type);
        A.push_back(cnt);
        cnt =  0;
    }

    i = 0, cnt = 0;
    type = b[0];
    while(i < m) {
        if(b[i] != type) {
            if(cnt != 0) {
                typeB.push_back(type);
                B.push_back(cnt);
                cnt =  1;
            }
        } else {
            cnt++;
        }
        type = b[i];
        i++;
    }
    if(cnt != 0) {
        typeB.push_back(type);
        B.push_back(cnt);
        cnt =  0;
    }

    int j = 0, k = 0;
    while(j < (int)A.size() && k < (int)B.size()) {
        if(typeA[j] != typeB[k]) {
            cout << "NO" << nl;
            return;
        }
        if(2 * A[j] < B[k] || B[k] < A[j]) {
            cout << "NO" << nl;
            return;
        }
        j++;
        k++;
    }

    cout << (j == (int)A.size() && k == (int)B.size() ? "YES" : "NO") << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

