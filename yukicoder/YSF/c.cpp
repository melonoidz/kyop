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
    int n,d; cin>>n>>d;
    vector<int> a(n,0);
    rep(i,n-1) cin>>a[i];
    vector<Int> ans;
    ans.emplace_back(0);
    vector<Int> dist(n,0);
    for(int i=0; i<n-1; i++){
        dist[i+1]=dist[i]+a[i];
    }
    Int tmp=dist[0];
    for(int i=1; i<n; i++){
        if(dist[i]-tmp<d){
            tmp+=d;
        }
        else {
            tmp=dist[i];
        }
        ans.emplace_back(tmp);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}