#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
map<ll,int> MP;

int main()
{
    int n,tmp;
	ll sum=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&tmp);
		sum+=tmp;
		MP[sum]++;
	}
	int cnt=0;
	for(auto it:MP)	cnt=max(it.se,cnt);
	cout<<n-cnt<<endl;
 return 0;
}

