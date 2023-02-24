#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mxn 100005 //array size
#define mxval 100005 //max array element
#define mxt 2000005 //max number of nodes needed, approximately n*(log(mxval)+4)
const int from=0, to=mxval;

int n, q, arr[mxn], w[mxt], nxt=1, in=0;
int lc[mxt], rc[mxt], l[mxt], r[mxt];
ll b[mxt];

void build(int psz=-1, bool f=1, int pnd=-1, int nd=1, int s=from, int e=to){
    l[nd]=++in, r[nd]=in-1;
    int midp=psz>>1, mid=(s+e)>>1, i1=(nd==1)?n:r[pnd];
    for(int i=(nd==1)?1:l[pnd]; i<=i1; i++)
        if(nd==1 || (f && w[i]<=midp) || (!f && w[i]>midp))
            w[in]=(nd==1)?arr[i]:w[i], r[nd]=in,
            b[in]=b[in-1]+(w[in]<=mid), in++;
    if(s==e) return;
    int sz=(nd==1)?n:r[nd]-l[nd]+1;
    if(b[r[nd]]-b[l[nd]-1]) lc[nd]=++nxt, build(s+e,1,nd,lc[nd],s,mid);
    if(b[r[nd]]-b[l[nd]-1]!=sz) rc[nd]=++nxt, build(s+e,0,nd,rc[nd],mid+1,e);
}

/*
note:
- w stores the array elements of each node
- b stores the prefix sum of frequency of elements <= mid of each node
- lc contains the node number of the left child of a node
- rc contains the node number of the right child of a node
- nxt is used to find the new node number to assign to a node
- in is used to allot space in the w array for each node
- [l[nd],r[nd]] is the range for elements of node nd in w and b
- psz is the number of elements in the parent of a node
- pnd is the parent of a node
- f is 1 if the current node is a left child, 0 otherwise
*/

//kth smallest element in range [l1,r1]
int kth(int l1, int r1, int k, int nd=1, int s=from, int e=to){
    if(s==e) return s;
    int mid=(s+e)>>1;
    int got=b[l[nd]+r1]-b[l[nd]+l1-1];
    if(got>=k) return kth(b[l[nd]+l1-1],b[l[nd]+r1]-1,k,lc[nd],s,mid);
    return kth(l1-b[l[nd]+l1-1],r1-b[l[nd]+r1],k-got,rc[nd],mid+1,e);
}

//count of k in range [l1,r1]
int count(int l1, int r1, int k, int nd=1, int s=from, int e=to){
    if(s==e) return b[l[nd]+r1]-b[l[nd]+l1-1];
    int mid=(s+e)>>1;
    if(mid>=k) return count(b[l[nd]+l1-1],b[l[nd]+r1]-1,k,lc[nd],s,mid);
    return count(l1-b[l[nd]+l1-1],r1-b[l[nd]+r1],k,rc[nd],mid+1,e);
}

//count of numbers <= to k in range [l1,r1] 
int LTE(int l1, int r1, int k, int nd=1, int s=from, int e=to){
    if(l1>r1 || k<s) return 0;
    if(e<=k) return r1-l1+1;
    int mid=(s+e)>>1;
    return LTE(b[l[nd]+l1-1],b[l[nd]+r1]-1,k,lc[nd],s,mid)+LTE(l1-b[l[nd]+l1-1],r1-b[l[nd]+r1],k,rc[nd],mid+1,e);
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];//1 based
    build();
    int q;
    cin>>q;
    while(q--){
        int x, l1, r1, k;
        cin >> x;
        cin >> l1 >> r1 >> k;
        l1--,r1--;//0 based
        if(x==0){
            //kth smallest
            cout << "Kth smallest: ";
            cout << kth(l1,r1,k) << endl;
        }
        if(x==1){
            //less than or equal to K
            cout << "LTE: ";
            cout << LTE(l1,r1,k) << endl;
        }
        if(x==2){
            //count occurence of K in [l, r]
            cout << "Occurence of K: ";
            cout << count(l1,r1,k) << endl;
        }
    }
    return 0;
}