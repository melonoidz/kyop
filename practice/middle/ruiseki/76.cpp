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
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<Int> a(n);
    rep(i,n) cin>>a[i];
    vector<Int> su(n+1);
    su[0]=0;
    for(int i=0; i<n; i++){
        su[i+1]=su[i]+a[i];
    } 
    for(int k=1; k<=n; k++ ){
        Int ans=0;
        for(int i=0; i<n-k+1; i++){
            Int tmp=su[i+k]-su[i];
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}