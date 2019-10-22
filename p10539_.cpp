#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#define sz 1000001
using namespace std;
vector<int>prime;
vector<long long int>ans;
bool flag[1000001];
int prsz;
void sieve(void)
{
    int i,j,add;
    flag[0]=flag[1]=1;
    prime.push_back(2);
    for(i=4; i<sz; i+=2)
        flag[i]=1;
    for(i=3; i<sz; i+=2)
    {
        if(!flag[i])
        {
            prime.push_back(i);
            if(sz/i>=i)
            {
                add=i*2;
                for(j=i*i; j<sz; j+=add)
                    flag[j]=1;
            }
        }

    }
}

int main()
{
    sieve();
    long long int i,k,szp,j;
    szp=prime.size();
    for(i=0; i<sz; i++)
    {
        if(!flag[i])
            for(j=i*i; j<1000000000001; j*=i)
                ans.push_back(j);

    }


    sort(ans.begin(),ans.end());
    int tst,count,ansz;
    ansz=ans.size();
    long long x,y;
    scanf("%d",&tst);
    while(tst--)
    {
        count=0;
        scanf("%lld %lld",&x,&y);
        i=0;
        while(ans[i]<x)i++;
        for(; i<ansz && ans[i]<=y; i++)
            count++;
        printf("%d\n",count);

    }

    return 0;
}
