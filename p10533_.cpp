#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include <bitset>
using namespace std;
typedef long long ll;

#define N 10000000

int lp[N+1];
bool isPrime[N+1];
vector<int> pr, digit;
void seive()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
            isPrime[i] = true;
        }
        for (int j=0; j< pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
}
void digit_pr()
{
    int l=pr.size();
   for(int i=0; i<l; i++){
        int sum=0;
        for(int j=pr[i]; j!=0; j=j/10){
            int ob=j%10;
            sum=sum+ob;
        }
        if(isPrime[sum]){ digit.push_back(pr[i]); }

   }
}
int main()
{
    seive();
    digit_pr();
    int n, t1, t2;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &t1, &t2);
        int cou=0;
        int i = (int)(lower_bound(digit.begin(), digit.end(), t1) - digit.begin() );
        for(; digit[i] <= t2 ; i++){cou++;}
        printf("%d\n", cou);
    }


    return 0;
}
