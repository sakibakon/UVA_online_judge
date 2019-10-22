#include<cstdio>
#include<queue>

using namespace std;

int ans [500000 + 5];

int main ()
{
    ans [1] = 1;
    ans [2] = 2;

    int next = 2;

    for ( int i = 3; i <= 500000; i++ ) {
        if ( i < next ) next = 2;
        ans [i] = next;
        next += 2;
    }

    int n;

    while ( scanf ("%d", &n) && n ) {
        printf ("%d\n", ans [n]);
    }

    return 0;
}
//another way...
using namespace std;
int main()
{
    int ans,n;
    while(scanf("%d", &n) && n){
        ans=0;
        queue<int> q1;
        if(n==1){printf("1\n");continue;}
        for(int j=2; j<=n; j+=2)q1.push(j);
        if(n%2==0){
            while(!q1.empty()){
                ans=q1.front();
                q1.pop();
                if(q1.empty())break;
                int s=q1.front();
                q1.pop();
                q1.push(s);
            }
        }
        else{
            while(!q1.empty()){
                ans=q1.front();
                q1.pop();
                q1.push(ans);
                q1.pop();
                if(q1.empty())break;

            }
        }
        printf("%d\n", ans);
    }
}
