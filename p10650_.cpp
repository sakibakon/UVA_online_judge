#include<bits/stdc++.h>
using namespace std;
#define mx 32001
bitset<mx>bt;
int prime[mx],e=-1;
vector<int>v[200];
void sieve()
    {
        bt[0]=bt[1]=1;
        prime[++e]=2;
        for(int i=4;i<mx;i+=2)bt[i]=1;
        for(int i=3;i*i<=mx;i+=2){
            if(!bt[i]){
                prime[++e]=i;
                for(int j=i*i;j<mx;j+=i)bt[j]=1;
            }
        }
        for(int i=179;i<mx;i+=2){
            if(!bt[i])prime[++e]=i;
        }
    }
void F(int a,int b)
    {
        int i=0,p=-1;
        while(i<=e && prime[i]<=b){
           if(a>prime[i]){i++;continue;}
            if( (prime[i+1]-prime[i]==prime[i+2]-prime[i+1]) && prime[i+1]<=b && prime[i+2]<=b){
                int t=prime[i+1]-prime[i];
                p++;
                v[p].push_back(prime[i]);
                v[p].push_back(prime[i+1]);
                v[p].push_back(prime[i+2]);
                i+=2;
                while(prime[i+1]-prime[i]==t){
                    v[p].push_back(prime[i+1]);
                    i++;
                }
            }
            else i++;
        }
    }
int main()
    {
        sieve();
        int a,b,c,d;
        F(0,32000);
        while(scanf("%d %d",&c,&d)){
            if(!c && !d)break;
            a=min(c,d);
            b=max(c,d);
            for(int i=0;i<162;i++){
                int x=v[i].size()-1;
                int t=v[i][0];
                int tt=v[i][x];
                if(t>=a && tt<=b){
                    printf("%d",v[i][0]);
                    for(int j=1;j<=x;j++)printf(" %d",v[i][j]);
                    printf("\n");
                }
            }
        }
        return 0;
    }
