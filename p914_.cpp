#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 1000001
using namespace std;

bool isP[maxN];
vector<int> prime;
int num[120];

void Sieve() {
    memset(isP, true, sizeof(isP));
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

main() {
    Sieve();
    int Case, n, m, low, up;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        memset(num, 0, sizeof(num));
        low = int(lower_bound(all(prime), n) - prime.begin());
        up = int(upper_bound(all(prime), m) - prime.begin());
        int Max = 0, idx = 0, Count = 0;
        for (int i=low+1; i<up; i++) {
            int tmp = prime[i] - prime[i-1];
            if (++num[tmp]>Max) {
                Max = num[tmp];
                idx = tmp;
            }
        }
        for(int i=1; i<114; i++){
            if (num[i]==Max) {
                if (++Count>1) break;
            }
        }
        if (Count>1 || Max==0) puts("No jumping champion");
        else printf("The jumping champion is %d\n", idx);
    }
}
