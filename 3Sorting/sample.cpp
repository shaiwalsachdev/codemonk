#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 100005;
const int MAX1 = 1000005;
int T,N;
int Weight[MAX],Frequency[MAX1],Aux[MAX],Copied[MAX],F[MAX1];
ll inv;
void mergeFunc(int left,int mid,int right)
{
    int p=left,q=mid+1,k=0,coun=0;
    for(int i=left;i<=right;i++)
    {
        if(p>mid)
        {
            Aux[k++] = Weight[q++];
        }
        else if(q>right)
        {
            Aux[k++] = Weight[p];
            Frequency[Weight[p]] += coun;
            p++;
        }
        else if(Weight[p] <= Weight[q])
        {
            Aux[k++] = Weight[p];
            Frequency[Weight[p]] += coun;
            p++;
        }
        else
        {
            Aux[k++] = Weight[q++];
            inv += mid-p+1;
            coun++;
        }
    }
    for(int i=0;i<k;i++)
    {
        Weight[left++] = Aux[i];
    }
}
void mergeSort(int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        mergeFunc(left,mid,right);
    }
}
int main()
{
   // freopen("input10.txt","r",stdin);
    //freopen("output10.txt","w",stdout);
    for(scanf("%d",&T);T;--T)
    {
        inv =0 ;
        for(int i=0;i<MAX1;i++)
        Frequency[i] = 0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&Weight[i]);
            Copied[i] = Weight[i];
        }
        mergeSort(0,N-1);
        ll sum = 0;
        for(int i=0;i<N;i++)
        {
            if(i != N-1)
            printf("%d ",Frequency[Copied[i]]);
            else
            printf("%d\n",Frequency[Copied[i]]);
        }
    }
    return 0;
}
