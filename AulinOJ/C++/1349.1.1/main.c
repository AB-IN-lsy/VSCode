#include <stdio.h>
#include <stdlib.h>
const int N=16;
int prim[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};
int dv(int x)
{
    if (x == 1)
        return 1;
    int pr[20],c,i,j;
    for(i=0;i<N;i++)
    {
        c = 1;
        while(x%prim[i] == 0)
        {
            x /= prim[i];
            c++;
        }
        pr[i] = c;
    }
    if(x!=1)
        pr[i++] = 2;
    int mul = 1;
    for(j=0;j<i;j++)
    {
        mul *= pr[j];
        //printf("%d ",pr[j]);
    }

    return mul;

}
int main()
{
    int m = -1,f;
    int a,b,i,x;
    scanf("%d%d",&a,&b);
    //a = 100;
    //b = 1000000000;
    int start = a>b/2?a:b/2;
    if(start%2 && b-start > 100)
        start++;
    int step;
    if(b-a>1e7)
        step = 100,start = start/100*100;
    else if(b-a>100)
        step = 2;
    else
        step = 1;
    for(i = start;i<=b;i+= step)
    {
        f = dv(i);
        if(m < f)
        {
            m = f;
            x = i;
        }

    }
    printf("%d,%d\n",m,x);
    return 0;
}
