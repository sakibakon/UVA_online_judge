#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000000
using namespace std;

bool mark [N];
vector <int> primeList,mi(2), mx(2);
vector<unsigned long int> renge;

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

void mi_mx()
{
   unsigned long int minn=1000000, maxx=0;
   unsigned long int l=renge.size()-1;
    for (unsigned long int i=0; i<l; i++){
          if ( (renge[i+1] - renge[i]) < minn ){
                minn = renge[i+1] - renge[i] ;
                mi[0]=renge[i]; mi[1]= renge[i+1];
          }
          if ( (renge[i+1] - renge[i]) >maxx ){
                maxx = renge[i+1] - renge[i] ;
                mx[0]=renge[i]; mx[1]= renge[i+1];
          }
   }
}
int main()
{
    unsigned long int L, U;
    sieve();
    while(scanf("%ld%ld", &L, &U)==2){
        if(L >= U){ printf("There are no adjacent primes.\n"); continue;}
        for( ; L<= U; L++){
            if(isPrime(L)){ renge.push_back(L); }
        }
        if(renge.size()<2){printf("There are no adjacent primes.\n"); }
        if(renge.size()>=2){
            mi_mx();
            printf("%ld,%ld are closest, %ld,%ld are most distant.\n",mi[0], mi[1], mx[0], mx[1]);
            mx.clear();
            mi.clear();
            renge.clear();
        }
        if(!renge.empty()){ renge.clear();}


    }


    return 0;
}
