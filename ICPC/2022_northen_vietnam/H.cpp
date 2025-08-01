#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define nl '\n'
typedef long long ll;
typedef pair<int,int> pi;

const int N = 1e5+1;
const ll INF = 998244353;

vector<vector<ll>> matMul(vector<vector<ll>>& a, vector<vector<ll>> b) {
    int n = a.size(), m = a[0].size(), p = b[0].size();
    assert(m == (int)b.size());
    vector<vector<ll>> c(n, vector<ll>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % INF;
            }
        }
    }

    return c;
}
struct Matrix {
    
    vector<vector<ll>> mat;
    Matrix() {};
    Matrix(vector<vector<ll>> a) {mat = a;}
    Matrix(int n, int m) {
        mat.resize(n);
        for(auto &x : mat) {
            x.resize(m);
        }
    }
    void iden() {
        for(int i = 0; i < (int)mat.size(); i++) {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix& a) {
        vector<vector<ll>> c = matMul(mat, a.mat);
        return Matrix(c);
    }
};
void solve() {
    
    ll n;
    cin>>n;

    Matrix mat(6,6), vec(6,1), cur(6,6); 

    cur.iden();

    mat.mat = {
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {2,4,1,12,12,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1},
        {0,0,0,2,4,1}
    };

    vec.mat = {{0},{12},{36},{1},{5},{11}};

    n--;
    while(n > 0) {
        if(n & 1) cur = cur * mat;
        mat = mat * mat;
        n >>= 1;
    }

    Matrix res;
    res = cur * vec;

    cout << res.mat[0][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
