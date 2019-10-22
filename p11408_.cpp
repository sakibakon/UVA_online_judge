#include<bits/stdc++.h>
using namespace std;

#define N 5000000
int lp[N+1];
bool isPrime[N+1];
vector<int> pr, v;
void seive()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
            isPrime[i] = true;
        }
        for (int j=0; j< pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
}

int primeFactors(int n)
{
    int sum=0;
    if(n%2==0)sum=2;
    while (n%2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        int z=0;
        while (n%i == 0)
        {
            if(z==0)sum=sum+i;
            n = n/i;
            z++;
        }
    }
    if (n > 2){
       sum+=n;
    }
    return sum;
}

int main()
{
    seive();
   long int n1, n2;
   while(scanf("%ld %ld",&n1,&n2)==2){
       int co=0;
        for(long int i=n1; i<=n2; i++){
            int n=0;
            if(isPrime[i]){ co++; continue; }
            n=primeFactors(i);
            if(isPrime[n]){ co++; }
        }
        printf("%d\n", co);
   }
}
