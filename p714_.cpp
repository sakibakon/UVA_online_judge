#include<stdio.h>

int main()
{
    unsigned long test;
    unsigned long a,b,n,m,k,i,j;
    long double sum,num;
    unsigned long v[500];
    long long avg;

    while(1==scanf("%lu",&test)){
        for(n=0;n<test;n++){
            sum=0;a=0;
            scanf("%lu%lu",&m,&k);
            for(j=0;j<m;j++){
                scanf("%lu",&v[j]);
                sum+=v[j];
            }
            avg=(sum/k);
            num=0;
            for(i=0;i<m;){
                num += v[i];
                if((num>avg)&&a!=k-1){
                    printf("/ ");
                    num=0;
                    a++;
                    continue;
                }
                else printf("%lu",v[i]);
                if(i!=(m-1))printf(" ");
                i++;
                if(i==m)break;
            }
            printf("\n");
        }
    }
}

