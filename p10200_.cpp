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


int main()
{
    long int n1, n2, an=0;
    sieve();
    while(scanf("%lld %lld",&n1, &n2)==2){
        double di=(n2-n1)+1;
        double c=0;
        for( ; n1<=n2; n1++){
            an=(n1*n1)+n1+41;
            if( isPrime(an) ){c++; }
        }
        double per=(c*100)/di;
        printf("%.2lf\n", ((c * 100.0)/di) + (1e-9));
    }
    return 0;
}
