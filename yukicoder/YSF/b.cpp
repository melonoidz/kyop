#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    int ans=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int tmp=n-i-j;
            if (
                0<=tmp&&tmp<=n
            ) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}