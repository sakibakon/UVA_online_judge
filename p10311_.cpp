#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

#define N 100000000


#define N 100000000
int lp[N+1];
bool isPrime[N+1];
vector<int> pr;
void sieve()
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

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
            bool found = true;
            if(n < 4 ) printf("%d is not the sum of two primes!\n",n);
            else if( n % 2  == 1 )
            {
                if(isPrime[n-2]) printf("%d is the sum of %d and %d.\n",n,2,n-2);
                else printf("%d is not the sum of two primes!\n",n);
            }
            else{
                int i= int(upper_bound(pr.begin(), pr.end(), n/2)- pr.begin());i--;
                while(i>0){
                    int k=n-pr[i];
                    if(isPrime[k] && k != pr[i]){ printf("%d is the sum of %d and %d.\n",n, pr[i] ,n-pr[i]); found= false; break; }
                    i--;
                }
                if(found){printf("%d is not the sum of two primes!\n",n);}
            }

    }
    return 0;
}
