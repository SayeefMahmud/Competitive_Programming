#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<(m); i++)
#define fro(m) for(int i=1; i<(m); i++)
#define frj(m) for(int j=0; j<(m); j++)
#define frr(n) for(int i=(n); i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<60)
#define inff (1<<30)-1
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn changeit

int n, A[(1<<20)+5];
int dp2[(1<<20)+5];

int main()
{
    fastio;
    cin>>n;
    for(int i=0; i<(1<<n); i++){
        cin>>A[i];
    }
    //base case
    for(int i=0; i<(1<<n); i++){
        dp2[i]=A[i];
    }
    for(int p=1; p<=n; p++){
        for(int i=0; i<(1<<n); i++){
            if(i&(1<<(p-1))){
                dp2[i]+=dp2[i^(1<<(p-1))];
            }
        }
    }

    //f[i]=dp[n][i]
    for(int i=0; i<(1<<n); i++){
        cout<<dp2[i]<<" ";
    }

    cout<<"\n";

    return 0;
}
