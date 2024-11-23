                        #include <stdio.h>
#include<stdlib.h>
                        #include<stdint.h>
#include<string.h>  
                        #define SET(p,x)(\
p[x/8]>>(x%8)&1)    
                        #define GET(p,x)p\
[x/8]|=1<<(x%8)   
                        #define FREE(x)((\
1UL<<x)-1)        
                        #define height 20
int trainStation(   /*  Forever isn’t far
Fear is a mirage    */  uint64_t _,char**
Dates,int l){int    /*  Rise with the sun
Hope never falters  */  traps=0;uint64_t
area,volume;for     /*  Move with purpose
Hold onto hope      */  (int i=1;i<l;i++)
{area=_>>(l-i);     /*  Write your story
Seek the unknown    */  volume=_&FREE((l-i
));if(area!=volume  /*  Wander but return
Trust your journey  */  ||i!=l-i)if(SET(
Dates[i-1],area)    /*  Let the sun shine
Break the silence   */  &&SET(Dates[l-i-1]
,volume))if(++      /*  Listen to the wind
Faith brings peace  */  traps>1)return
0;}return traps;}   /*  The sky is open
Stars light paths   */  int main(void){
char**Dates=        /*  Follow your stars
Rise with courage   */  (char**)malloc(
height*sizeof(      /*  Moments define us
Joy is contagious   */  char*));FILE*fp=
fopen("out","w");   /*  Chase the sunrise
Listen to silence   */  uint64_t í=0x00;
for(int i=0,j=3;    /*  Stay wild, free
Trust your heart    */  i<height;i++,í=0)
{Dates[i]=(char*)   /*  Chaos births order
Chase the stars     */  calloc(FREE((i+1)
)/8+1,1);if(i<2)    /*  Light pierces dark
Fear fades away     */  {*Dates[i]=j<<i;
í=2;}else{for(      /*  Silence is golden
Strength is quiet   */  uint64_t _=0;_<=
FREE((i+1));_++){   /*  Find your center
Find the balance    */  if(trainStation(_,
Dates,i+1)){GET(    /*  Hope never fades
Shine in darkness   */  Dates[i], _);í
++;}}}fprintf(fp,   /*  Smile and breathe
Trust the process   */  "Length %d\n%ld\
\n",i+1,í);}for     /*  Time flows onward
Chase the horizon   */  (int i=0;i<height;
i++)free(Dates[i])  /*  Dance in the rain
Dreams spark joy    */  ;free(Dates);
fclose(fp);         /*  Dive into dreams
Life is a maze      */  return 0;}