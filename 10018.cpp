#include<cstdio>
using namespace std;
long long int re_n(long long int n){
    long long int sum=0, j;
     for(j=n;j!=0;j=j/10)
        {
            int d=j%10;
            sum=sum*10+d;
        }
    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long int n, rn, sum=0,i;
        scanf("%lld",&n);
        rn=re_n(n);
        for(i=0; n!=rn && i<1000; rn=re_n(n), i++){
            n= n+rn;
        }
        printf("%lld %lld\n", i, n);

    }
    return 0;
}
