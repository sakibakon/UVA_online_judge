#include<cstdio>
#include<cmath>

using namespace std;
double x, h, y;
double f_hight(double d)
{
    double h1, h2, result;
    h1=sqrt( (x*x)-(d*d));
    h2=sqrt( (y*y)-(d*d));
    result= ((h1*h2)/(h1+h2));
    return result;

}
int main()
{
    while(scanf("%lf %lf %lf",&y ,&x ,&h)!= EOF ){
        double low=0, up, high;
        if(x<y)up=x;
        else{ up=y; }
        double d =(up/2);
        int n=30;
        while(n--){
            double h1, h2, result;
            h1=sqrt( (x*x)-(d*d));
            h2=sqrt( (y*y)-(d*d));
            high = ((h1*h2)/(h1+h2));
            if(high<h)up=d;
            if(high>h)low=d;
            d =((low+up)/2);
        }
        printf("%.3lf\n", d);
    }
}
