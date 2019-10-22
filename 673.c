#include<stdio.h>
int main()
{
    int n, i, I, ln, fals=0;
    char s[129];
    scanf("%d",&n);
    getchar();
    while(n>0){
        fals=0;
        gets(s);
        ln=strlen(s);
        for(i=0; i<ln; i++){
            if(s[i]==41 || s[i]==93){
                I=1;
                if(i!=0){
                    while(s[i-I]!=40 && s[i-I]!=41 && s[i-I]!=91 && s[i-I]!=93){
                        if((i-I)==0){fals=1; break;}
                        I++;
                    }
                }
                if(i==0){fals=1; }
                if(fals==1){ }
                else if(s[i]==')' && s[i-I]=='(' ){s[i]=0; s[i-I]=0;}
                else if(s[i]==']' && s[i-I]=='['){s[i]=0; s[i-I]=0; }
                else{fals=1;}
            }
            if(fals==1){break; }
        }
        for(i=0; i<ln; i++){
            if(s[i]=='(' || s[i]==')' || s[i]=='[' || s[i]==']' ){fals=1; printf("No\n"); break; }
        }

        if(fals==0){printf("Yes\n");}
        n--;
    }
    return 0;
}
