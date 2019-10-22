#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, ds=0, hs=0;
        scanf("%d",&n);
        vector<int>db,hb;
        for(int i=n; i>0; i=i/2){
            if(i%2==0){db.push_back(0);}
            else{db.push_back(1); ds++;}
        }
        printf("%d ",ds);

        for(int k, i=n; i!=0; i=i/10){
            k=i%10;
            if(k==0){ }
            else if(k==1){ hs=hs+1;}
            else if(k==2){ hs=hs+1;}
            else if(k==3){ hs=hs+2;}
            else if(k==4){ hs=hs+1;}
            else if(k==5){ hs=hs+2;}
            else if(k==6){ hs=hs+2;}
            else if(k==7){ hs=hs+3;}
            else if(k==8){ hs=hs+1;}
            else if(k==9){ hs=hs+2;}
        }
        printf("%d\n",hs);
    }
}
