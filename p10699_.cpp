// Program to print all prime factors
# include <stdio.h>
# include <math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long int> v;

void primeFactors(long int n)
{
    if(n%2==0)v.push_back(2);
    while (n%2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        int c=0;
        while (n%i == 0)
        {
            if(c==0){v.push_back(i);}
            n = n/i;
            c++;
        }
    }
    if (n > 2){
        bool k=binary_search(v.begin(), v.end(), n);
        if( !k )v.push_back(n);
    }
}

int main()
{
    long int n;
    while(scanf("%ld",&n)==1 && n){
        v.clear();
        primeFactors(n);
        int l=v.size();
        printf("%ld : %d\n",n , l);
    }
    return 0;
}

