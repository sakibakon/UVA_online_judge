#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr, s, t;

bool comp(const int& L, const int& R){
    if(s[L] * t[R] == s[R] * t[L]) return L < R;
    return s[L] * t[R] < s[R] * t[L];
}

int main(){
    int TC;
    cin >> TC;
    bool flag = false;
    while(TC--){
        if(flag) printf("\n");
        flag = true;
        int N;
        cin >> N;
        arr.clear();
        s.clear();
        t.clear();
        for(int i=0;i<N;++i){
            int u,v;
            cin >> u >> v;
            s.push_back(u);
            t.push_back(v);
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end(), comp);
        for(int i=0;i<N;++i){
            if(i != 0) printf(" ");
            printf("%d", arr[i]+1);
        }
        printf("\n");
    }
    return 0;
}
