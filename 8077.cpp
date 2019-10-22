#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fun(ll y1, ll y2)
{
    return abs((y2-y1)-1);

}

int main()
{
    ll x1, x2, y1, y2;
    while(scanf("%lld %lld %lld %lld", &y1, &x1, &y2, &x2)==4){
        if(x1==0 && x2==0 && y1==0 & y2==0)break;
        if(y1==y2){ printf("%lld\n", abs(x1-x2)); continue; }
        if(y1>y2){swap(y1, y2); swap(x1, x2); }
        if( (x1+y1)%2==0 ){
            ll ans = fun(y1, y2);
            ll tx1=x1-ans, tx2=x1+ans;
            if(tx1<=x2 && tx2>=x2){
                if((y2+x2)%2==1)printf("%lld\n", abs(y1-y2)+ans );
                else printf("%lld\n", abs(y1-y2)+1+ans );
            }
            else if(tx1>x2)printf("%lld\n", abs(y1-y2)+abs(tx1-x2)+ans );
            else printf("%lld\n", abs(y2-y1)+abs(x2-tx2)+ans );

        }
        else{
            if(x2>x1)x1++;
            else x1--;
            if( (x1+y1)%2==0 ){
                ll ans = fun(y1, y2);
                ll tx1=x1-ans, tx2=x1+ans;
                if(tx1<=x2 && tx2>=x2){
                    if((y2+x2)%2==1)printf("%lld\n", abs(y1-y2)+1+ans );
                    else printf("%lld\n", abs(y1-y2)+2+ans );
                }
                else if(tx1>x2)printf("%lld\n", abs(y1-y2)+abs(tx1-x2)+1+ans );
                else printf("%lld\n", abs(y2-y1)+abs(x2-tx2)+1+ans );

            }

        }

    }


}
