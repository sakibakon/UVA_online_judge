#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

#define N 20000001


#define N 20000001
int lp[N+1], tw[N], co=1, j=2;
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
void twin (){
    for(int i=3; i<N; i+=2){
        if(isPrime[i] && isPrime[i+2]){
          tw[co++]= i;
        }
    }
}
int main()
{
    sieve();
    twin();
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("(%d, %d)\n", tw[n], tw[n]+2);
    }
    return 0;
}

