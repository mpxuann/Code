#include<stdio.h>
#include<stdlib.h>

struct _card
{
    int x;
    int y;
}randcard[108];

char* shape[6] = {"Club","Heart","Spade","Diomand","N","C"};
char* num[14] = {"3","4","5","6","7","8","9","10","J","Q","K","A","2","Joker"};
int a[54] = {0},b[54]={0};
int main()
{
    int m,d;
    int i = 0;
    srand(time(NULL));
    for(;i<108;++i)
    {
        m = rand()%54;
        while(a[m]==2)
            m = rand()%54;
        d = i % 4 *27 + i / 4;
        if(m<52)
        {
            randcard[d].x = m / 13;
            randcard[d].y = m % 13;
        }
        else
        {
             randcard[d].x = m % 13 + 4;
            randcard[d].y = 13;

        }
        a[m] ++;
      
    }
   
    for(i = 0;i<108;i++)
    {
        if(i%27 == 0)
            printf("player%d :\n",(i/27)+1);
       
        printf("%-9s%s\n",shape[randcard[i].x],num[randcard[i].y]);
     
    }
    system("pause");
    return 0;
}