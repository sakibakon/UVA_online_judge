#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef vector<int> r_egg;
int main()
{

    int n_nod, n_in, x, y, c=1;
    scanf("%d", &n_nod);
    while(n_nod){
        vector<r_egg>ve(n_nod+1);
        vector<int>colour(n_nod+1, 2);
        int t=1;
        scanf("%d", &n_in);

        while(n_in){
          scanf("%d%d", &x, &y);
          ve[x].push_back(y);
          ve[y].push_back(x);
          n_in--;
        }
        queue<int>Q;
        Q.push(0);
        colour[0]=1;
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=0; i<ve[u].size(); i++){
                if(colour[ve[u][i]] == 2){
                    colour[ve[u][i]] =1- colour[u];
                    Q.push(ve[u][i]);
                }
                else{
                    if(colour[ve[u][i]] == colour[u] ){ t=0; break; }
                }

            }
            if(t==0){break;}
        }
        if(t==0){ printf("NOT BICOLORABLE.\n");}
        else{ printf("BICOLORABLE.\n");}
        scanf("%d", &n_nod);

    }



    return 0;
}

