#include <cstdio>
#include <cstring>

using namespace std;
static int table[128];
void PreSum(){
    register unsigned i, j = 1;

    for (i = 'a'; i <= 'z'; ++i, ++j)
        table[i] = j;

    for (i = 'A'; i <= 'Z'; ++i, ++j)
        table[i] = j;
}

bool is_prime(int n){
    if(n <= 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3;i*i <= n ;i += 2)
        if(n % i == 0) return false;

    return true;
}

int main(){
    char s[21];
    PreSum();
    int i;

    while(scanf("%s",s) == 1){
        int sum=0;
        for (i = 0; s[i]; ++i){
            sum += table[s[i]];
        }

        if (is_prime(sum))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }

    return 0;
}
