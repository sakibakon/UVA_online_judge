#include<bits/stdc++.h>
using namespace std;
long long int rnd( long long int z, long long int i, long long int m, long long int l)
{
    l=(z*l)+i;
    l=l%m;
    return l;
}

int main()
{
    long long int z, i, m, l, root, L;
    int ca=1;
    while(scanf("%lld%lld%lld%lld",&z,&i,&m,&l)==4){
        int co=0, c=0;
        vector<long int> v;
        if(z==0 && i==0 && m==0 && l==0)break;
        root= l;
        L=rnd( z, i, m, l);
        v.push_back(l);
        for(int i=0; i<v.size(); i++){
                int j=v.size();
                if(L==v[i]){ co=j-i; c=1; break;}
        }
        v.push_back(L);
        while(c==0){
            L=rnd(z, i, m, L);
            for(int i=0; i<v.size(); i++){
                int j=v.size();
                if(L==v[i]){ co=j-i; c=1; break;}
            }
            v.push_back(L);
        }
        printf("Case %d: %d\n",ca++, co);

    }
    return 0;
}

