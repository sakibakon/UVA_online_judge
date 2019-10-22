#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long int n1, n2;
        scanf("%ld%ld",&n1,&n2);
        if(n1>n2)printf(">\n");
        else if(n1<n2)printf("<\n");
        else{ printf("=\n"); }
    }
    return 0;
}
