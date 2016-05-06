#include<bits/stdc++.h>
using namespace std;
#define lx long long
const int maxn = 1e6;
int prime[maxn];
vector<int> v[maxn];
lx int get_phi(lx int x,vector<int>&pr)
{
    lx int ans = x;
    for (int i=0;i<pr.size();i++)
    {
        while(x%pr[i]==0)
            x/=pr[i];
        ans = ans/pr[i]*(pr[i]-1);
    }
    if (x>1)
        ans=ans/x*(x-1);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
   
    prime[1]=1;
    for (int i=2;i<=maxn;i++)
    {
        if(prime[i]==0)
        {
            for (int j=i*2;j<=maxn;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        lx int l,r,k;
        cin>>l>>r>>k;
        for (lx int i =l;i<=r;i++)
            v[i-l].clear();
        for (int i=2;i<=maxn;i++)
        {
            if (prime[i])
                continue;   // if not prime continue
            lx int band=l/i*i;
            if (l%i)
            {
                band+=i;
            }
            for (lx int j = band ; j<=r ;j+=i)
                v[j-l].push_back(i);
        }
        int ans = 0;
        for (lx int i=l;i<=r;i++)
        {
            lx int q = get_phi(i,v[i-l]);
            if (q%k==0)
                ans++;
        }
       cout<<fixed<<setprecision(6)<<(ans*1.0)/(r-l+1)<<endl;
    }
    return 0;
}
