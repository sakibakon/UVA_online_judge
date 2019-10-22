#include<stdio.h>
#include<vector>
#include<cstring>
#include<string.h>
#define N 2001
using namespace std;
bool mark [N];
vector<int>prime;
void sive()
{
    memset (mark, true, sizeof (mark));
     mark [0] = mark [1] = false;
     for(int i=4; i<=N; i+=2)mark[i]=false;
     prime.push_back(2);
     for(int i=3; i<=N; i+=2){
        if(mark[i]){
            prime.push_back(i);
            for(int j=i*i; j<= N; j+= 2*i)mark[j]= false;
        }
     }
}
int main()
{
    sive();
    int t, k;
    scanf("%d", &t);
    getchar();
    int c=1;
    while(t--){
        char s[2002];
        scanf("%s",s);
        vector<int> b(124, 0);
        for(int i=0; i<strlen(s); i++){
            b[s[i]]++;
        }
        int cou=0;
        printf("Case %d: ", c++);
        for(int i='0'; i<='z'; i++){
            if( mark[b[i]] ){ printf("%c", i); cou++; }
        }
        if(!cou)printf("empty");
        printf("\n");
    }
    return 0;
}
