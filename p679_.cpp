#include<cstdio>
using namespace std;
int de,d;
int ball(int bal, int a)
{
    de++;
    int att= a*2;
    if(de==d){
        if( bal%2==0) return att+1;
        else{ return att; }
    }
    if( bal%2==0)return ball(bal/2, att+1);
    else{ return ball((bal/2)+1, att); }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int bal,ans;
        scanf("%d%d", &d, &bal);
        de=1;
        ans= ball(bal, 1);
        printf("%d\n", ans);
    }
    int last;
    scanf("%d", &last);
}
