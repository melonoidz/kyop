#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    long double x, y, r;
    cin >> x >> y >> r;
    r += 1e-14;
    int left = ceil(x - r);
    int right = floor(x + r);
    int ans = 0;
    for (int i = left; i <= right; i++) {
        long double y_p, y_n;
        long double tmp1, tmp2;
        long double sq = ((long double)i - x) * ((long double)i - x);

        tmp1 = (long double)y + sqrtl(r * r - sq);
        y_p = floor(tmp1);

        tmp2 = (long double)y - sqrtl(r * r - sq);
        y_n = ceil(tmp2);

        ans += (y_p - y_n) + 1;
    }
    cout << ans << endl;
    return 0;
}