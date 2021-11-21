#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<sstream>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define orr ||
#define nl printf("\n")
#define sci(n) scanf("%lld ", &n)
#define scl(n) scanf("%lld", &n)
#define pri(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define prc(n) printf("%c", n)
#define prs printf(" ")
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define debug(arr,n) for(int i=0; i<n; i++) printf("%lld ", arr[i])
#define debugr(arr,s,e) for(int i=s; i<=e; i++) printf("%lld ", arr[i])

int main()
{
    ll nodes, edges;
    cin>>nodes>>edges;
    vector<ll>vec[nodes+1],indegree[nodes+1];
    fr(edges){
        ll node1, node2;
        cin>>node1>>node2;
        vec[node1].pb(node2);
        indegree[node2].pb(node1);
    }
    for(int i=1; i<=nodes; i++){
        cout<<"outdegree"<<endl;
        if(!vec[i].empty()){
            cout<<vec[i].size()<<endl;
            for(ll b:vec[i]) cout<<b<<" ";
            nl;
        }
        cout<<"indegree"<<endl;
        if(!indegree[i].empty()){
            cout<<indegree[i].size()<<endl;
            for(ll b:indegree[i]) cout<<b<<" ";
            nl;
        }
    }
    return 0;
}

