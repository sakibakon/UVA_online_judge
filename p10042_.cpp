# include <stdio.h>
# include <math.h>
#include<vector>
using namespace std;
vector<long long int> v;

void primeFactor(long long int n)
{
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2){
        v.push_back(n);
    }
}
long long int primeSum(){
    long long int sum=0, l=v.size();
    for(int i=0; i<l; i++ ){
        for(long long int n=v[i]; n>0; n=n/10){
            int k=n%10;
            sum=sum+k;
        }
    }
    return sum;
}
int isprime(long long int n)
{
    if(n<=1){ return 0;}
    for(long long int i=2; i*i<=n; i++ ){
        if(n%i==0){return 0; }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long int n;
        scanf("%lld", &n);
        while(n++){
            if(isprime(n)){continue; }
            long long int sum=0, primeSm=0;
            v.clear();
            for(long long int k=n ; k>0 ; k=k/10 ){
                int i=k%10;
                sum=sum+i;
            }
            primeFactor(n);
            primeSm= primeSum();
            if(sum == primeSm){printf("%lld\n", n); break; }

        }
    }


    return 0;
}

