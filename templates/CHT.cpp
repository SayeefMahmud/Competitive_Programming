
/*
1. mi > mi+1, minimum.
2. mi > mi+1, maximum.
3. mi < mi+1, minimum.
4. mi < mi+1, maximum.
*/

struct line{
    ll m, c;
    line(ll a, ll b){
        m=a, c=b;
    }
};

struct CHT{
    vector<line>v;
    int t, ptr;
    void init(int tp){
        t=tp, ptr=0, v.clear();
    }
    CHT(int tp){
        t=tp, ptr=0;
    }
    bool bad(line l1, line l2, line l3){
        __int128 a=(__int128)(l3.c-l1.c)*(l1.m-l2.m);
        __int128 b=(__int128)(l2.c-l1.c)*(l1.m-l3.m);
        if(t==1 orr t==4) return a<=b;
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
    ll query1(ll x){//ternary search
        int l=0, r=v.size()-1;
        ll ans=0;
        while(l<=r){
            int mid1=l+(r-l)/3, mid2=r-(r-l)/3;
            if(t&1){
                if(val(mid1,x)<=val(mid2,x)) r=mid2-1, ans=val(mid1,x);
                else l=mid1+1, ans=val(mid2,x);
            }
            else{
                if(val(mid1,x)>=val(mid2,x)) r=mid2-1, ans=val(mid1,x);
                else l=mid1+1, ans=val(mid2,x);
            }
        }
        return ans;
    }
    ll query2(ll x){//1,4 if xi<=xi+1; 2,3 if xi>=xi+1
        if(v.empty()) return 0;
        if(ptr>=v.size()) ptr=v.size()-1;
        while(ptr<v.size()-1){
            if(t&1){
                if(val(ptr,x)>val(ptr+1,x)) ptr++;
                else break;
            }
            else{
                if(val(ptr,x)<val(ptr+1,x)) ptr++;
                else break;
            }
        }
        return val(ptr,x);
    }
};
