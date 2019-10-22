#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
bool mark [10001];
vector<int>prime;
void sive()
{
    memset (mark, true, sizeof (mark));
     mark [0] = mark [1] = false;
     for(int i=4; i<=10001; i+=2)mark[i]=false;
     prime.push_back(2);
     for(int i=3; i<=10001; i+=2){
        if(mark[i]){
            prime.push_back(i);
            for(int j=i*i; j<= 10001; j+= 2*i)mark[j]= false;
        }
     }
}
int main()
{
    sive();
    int t;
    scanf("%d", &t);
    while(t--){
        int n, a;
        scanf("%d", &n);
        n=(n/2)+1;
        a=int(lower_bound(prime.begin(), prime.end(), n)- prime.begin());
        printf("%d\n",prime[a]);
    }

    return 0;
}
