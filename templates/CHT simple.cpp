#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<61)
#define inff (1<<30)
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn 200005

struct line{
    ll m, c;
    line(ll a, ll b){
        m=a, c=b;
    }
};

struct CHT{
    vector<line>v;
    void init(int tp){
        v.clear();
    }
    bool bad(line l1, line l2, line l3){
        __int128 a=(__int128)(l2.c-l1.c)*(l2.m-l3.m);
        __int128 b=(__int128)(l3.c-l2.c)*(l1.m-l2.m);
        return a>=b;
    }
    void add(line a){
        v.pb(a);
        int sz=v.size();
        while(sz>=3 && bad(v[sz-3],v[sz-2],v[sz-1])){
            v.erase(v.end()-2), sz--;
        }
    }
    inline ll val(int ind, ll x){
        return v[ind].m*x+v[ind].c;
    }
    ll query(ll x){//ternary search
        int l=0, r=v.size()-1;
        ll ans=0;
        while(l<=r){
            int mid1=l+(r-l)/3, mid2=r-(r-l)/3;
            if(val(mid1,x)<=val(mid2,x)) r=mid2-1, ans=val(mid1,x);
            else l=mid1+1, ans=val(mid2,x);
        }
        return ans;
    }
};

ll n, c, h[mxn], dp[mxn];

int main()
{
    fastio;
    cin>>n>>c;
    for(int i=1; i<=n; i++) cin>>h[i];
    CHT C;
    dp[1]=0;
    C.add({-2*h[1],h[1]*h[1]+dp[1]});
    for(int i=2; i<=n; i++){
        dp[i]=c+h[i]*h[i]+C.query(h[i]);
        C.add({-2*h[i],h[i]*h[i]+dp[i]});
    }
    cout<<dp[n]<<nl;
    return 0;
}