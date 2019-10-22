#include <stdio.h>

using namespace std;
long long Mod(long long a, long long k, long long p)
{
    if (k==1) return a%p;
    long long int tmp = Mod(a, k/2, p);
    tmp = (tmp*tmp) % p;
    if (k%2) return (tmp*a)%p;
    return tmp;
}
int isPrime(int x) {
    int i;
    for(i = 2; i*i <= x; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
int main() {
    long long p, a;
    while(scanf("%lld %lld", &p, &a) == 2) {
        if(p == 0 && a == 0)
            break;
        if(isPrime(p) || Mod(a, p, p) != a)
            puts("no");
        else
            puts("yes");
    }
    return 0;
}
