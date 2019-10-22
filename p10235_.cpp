#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000000
using namespace std;

bool mark [N];
vector <int> primeList;

void sieve ()
{
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;

    for ( int i = 3; i * i <= N; i++ ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

bool isPrime (int n)
{
    if ( n < N ) return mark [n];

    int index = 0;

    while ( primeList [index] * primeList [index] <= n ) {
        if ( n % primeList [index] == 0 ) return false;
        index++;
    }

    return true;
}

int main ()
{
    sieve ();
    long long int n, k;
    while(scanf("%lld",&n)==1){
        k=n;
        if(isPrime(n)){
            long long int sum=0;
            for( ; n!=0; n=n/10){
                int d=n%10;
                sum=(sum*10)+d;
            }
            if(isPrime(sum) && sum!=k){
                printf("%lld is emirp.\n", k);
            }
            else{ printf("%lld is prime.\n", k);}
        }
        else{ printf("%lld is not prime.\n", k);}
    }


    return 0;
}


