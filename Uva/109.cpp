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
#define sz(x) x.size()
const char nl = '\n';
const int N =21+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
vector<P> convexHull(vector<P>& pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class T>
bool check(vector<Point<T>>& now, Point<T> bomb) {
    
    P p1 = now[0];
    int intersect = 0;
    for(int i = 1; i <= (int)now.size(); i++) {
        P p2 = now[i % now.size()];
        
        if(bomb.y < p1.y != bomb.y < p2.y) {
            double x0 = (bomb.y - p1.y) / (p2.y - p1.y) * (p2.x - p1.x) + p1.x;
            if(bomb.x <= x0) {
                intersect++;
            }
        }
        p1 = p2;
    }

    return (intersect % 2 == 1);
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	for(int i = 0; i < sz(v) - 1; i++) a += v[i].cross(v[i+1]);
	return a;
}

vector<P> a[N];
double area[N];
bool vis[N];
int n, cur = 0;
void solve(){

    memset(area, 0, sizeof area);
    memset(vis, false, sizeof vis);
    while(cin>>n) {
        if(n == -1) break;
        for(int i = 0; i < n; i++) {
            double x,y;
            cin>>x>>y;
            a[cur].push_back(P(x,y));
        }
        a[cur] = convexHull(a[cur]);
        area[cur] = polygonArea2(a[cur]);
        //cout << area[cur] << nl;
        cur++;
    }

    P bomb;
    while(cin>>bomb.x>>bomb.y) {
        for(int i =0; i < cur; i++) {
            if(check(a[i], bomb)) {
                vis[i] = true;
            }
        }
    }

    double ans = 0;
    for(int i = 0; i < cur; i++) {
        if(vis[i]) {
            //cout << i << nl;
            ans += area[i];
        }
    }

    ans /= 2.00;
    cout << fixed << setprecision(2) << ans << nl;
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

