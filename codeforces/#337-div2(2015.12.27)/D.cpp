#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct Seg{
    int s;
    long long l,r,h;
}edge[MAXN];
long long cnt[MAXN<<2]={0},sum[MAXN<<2]={0};
int n;
long long pos[MAXN];

void t_update(int ll,int rr,int s,int l,int r,int rt)
{
    int m=(l+r)/2;
    if(l==ll&&r==rr){
        cnt[rt]+=s;
        if(cnt[rt]) sum[rt]=pos[r+1]-pos[l];
        else
            if(l==r) sum[rt] = 0;
        else
            sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        return;
    }
    if(rr<=m) t_update(ll,rr,s,l,m,rt<<1);
    else if(ll>m) t_update(ll,rr,s,m+1,r,rt<<1|1);
    else{
        t_update(ll,m,s,l,m,rt<<1);
        t_update(m+1,rr,s,m+1,r,rt<<1|1);
    }
    if(cnt[rt]) sum[rt]=pos[r+1]-pos[l];
    else
        if(l==r) sum[rt]=0;
    else
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int b_search(long long v ,int n)
{
    int l=1,r=n,m;
    while(l<=r){
        m=(l+r)>>1;
        if(pos[m]==v) return m;
        if(pos[m]<v) l=m+1;
        else r=m-1;
    }
    return -1;
}

bool cmp(const Seg &x,const Seg &y)
{
    return x.h<y.h;
}

int main()
{
    int i,j,k=1,len,l,r;
    long long x1,x2,y1,y2;
    long long a,b,c,d;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        a=min(x1,x2);
        b=min(y1,y2);
        c=max(x1+1,x2+1);
        d=max(y1+1,y2+1);
        pos[k]=a;edge[k].l=a;edge[k].r=c;edge[k].h=b;edge[k].s=1;
        ++k;
        pos[k]=c;edge[k].l=a;edge[k].r=c;edge[k].h=d;edge[k].s=-1;
        ++k;
    }
    len=2;
    sort(pos+1,pos+k);
    sort(edge+1,edge+k,cmp);
    for(i=2;i<k;i++)
        if(pos[i]!=pos[i-1])
            pos[len++]=pos[i];
    for(i=1;i<k;i++){
        l=b_search(edge[i].l,len-1);
        r=b_search(edge[i].r,len-1);
        r--;
        if(l<=r) t_update(l,r,edge[i].s,1,len-2,1);
        ans+=(edge[i+1].h-edge[i].h)*sum[1];
    }
    cout<<ans<<endl;
    return 0;
}
