#include<cstdio>
#include<string.h>
int main()
{

    int t, day,mn, yr, mi=95000, mx=0;
    scanf("%d", &t);
    char name[15], sn[15], bn[15];
    while(t--){
        scanf("%s %d%d%d" ,&name,&day,&mn,&yr);
        yr = yr-1910;
        day=(yr*365)+(mn*30)+day;
        if(day<mi){ strcpy(sn, name); mi=day; }
        if(day>mx){ strcpy(bn, name); mx=day; }

    }
    printf("%s\n", bn);
    printf("%s", sn);
    return 0;
}
