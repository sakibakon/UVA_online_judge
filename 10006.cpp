#include<cstdio>
#include<cmath>
using namespace std;
int bigmod(int a, long int p,long int m){
    if(p==0){return 1;}
    if(p%2==0){
        long int c=bigmod(a, p/2, m);
        return ((c%m)*(c%m))%m;
    }
    else{return ((a%m)*(bigmod(a,p-1,m)))%m; }
}

int main()
{

    long int n,mod,sq;
    while(scanf("%ld",&n)){
        int bo=0;
        if(n==0){break;}
        sq=sqrt(n);
        for(int a=2,i=0; a<n; a++){
            mod=bigmod(a, n, n);
            if(mod==a){ i++; if(i>2){ mod=sq; break;}}
        }
        if(mod==2){

            for(int i=2; i<=sq; i++){
                if(n%i==0){bo=1; printf("The number %ld is a Carmichael number.\n", n); break;}
            }

        }
        if(bo==0){printf("%ld is normal.\n",n);}
    }
    return 0;
}
