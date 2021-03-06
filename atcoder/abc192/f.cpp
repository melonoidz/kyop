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
int n, x;
const int INF = 1LL << 60;
vc<int> a;
int calc(int k, const vc<int>& a) {
    // i番目をみておりすでにj個の素材を使用している時，modK=mとなる時の魔力のmaxsum
    vc<vc<vc<int>>> dp(n + 1, vc<vc<int>>(k + 2, vc<int>(k + 1, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int m = 0; m < k; m++) {
                if (dp[i][j][m] == -INF) continue;
                dp[i + 1][j][m] = max(dp[i + 1][j][m], dp[i][j][m]);
                dp[i + 1][j + 1][(m + a[i]) % k] =
                    max(dp[i + 1][j + 1][(m + a[i]) % k], dp[i][j][m] + a[i]);
            }
        }
    }
    int res = dp[n][k][x % k];
    if (res == -INF) return INF;
    return (x - res) / k;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> x;
    a.resize(n);
    rep(i, n) cin >> a[i];
    // k個選んだ時にres%k == x%k となるtime=min{(x-res)%k}を求める
    // sum(A)<=XなのでOK
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, calc(i, a));
    }
    cout << ans << endl;
}