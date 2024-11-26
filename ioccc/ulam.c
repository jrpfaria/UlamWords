                        #include <stdio.h>
#include<stdlib.h>
                        #include<stdint.h>
#include<string.h>  
                        #define SET(p,x)(\
p[x/'']>>(x%8)&1)    
                        #define GET(p,x)p\
[x/'']|=1<<(x%8)   
                        #define FREE(x)((\
1UL<<x)-1)        
                        #define height 40
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
(i-1)[Dates],area)  /*  Let the sun shine
Break the silence   */  &&SET((l-i-1)
[Dates],volume))if  /*  Listen to the wind
Faith brings peace  */  (++traps>1)return
0;}return traps;}   /*  The sky is open
Stars light paths   */  int main(void){
char**Dates=        /*  Follow your stars
Rise with courage   */  (char**)malloc(
height*sizeof(      /*  Moments define us
Joy is contagious   */  char*)); uint64_t
í=''-1;char* ç=     /*  Chase the sunrise
Listen to silence   */  ".GPIVJ";for(
int j=3,i=''-j;     /*  Stay wild, free
Trust your heart    */  i<height;i++,í=0)
{i[Dates]=(char*)   /*  Chaos births order
Chase the stars     */  calloc(FREE((i+1)
)/''+1,1);if(i<2)   /*  Light pierces dark
Fear fades away     */  {*i[Dates]=j<<i;
í=2;}else{for(      /*  Silence is golden
Strength is quiet   */  uint64_t _=0;_<=
FREE((i+1));_++){   /*  Find your center
Find the balance    */  if(trainStation(_,
Dates,i+1)){GET(    /*  Hope never fades
Shine in darkness   */  i[Dates], _);í++;
}}}int a=''-'';     /*  Smile and breathe
Trust the process   */  for(;*(ç+a++)!=''
;)printf("%c",*     /*  Embrace the storm
Life is a maze      */  (ç+a)+30);printf(  
"%d\n%ld\n",i+1,í)  /*  Time flows onward
Chase the horizon   */  ;}for(int i=0;i<
height;i++)free(i   /*  Dance in the rain
Dreams spark joy    */  [Dates]);free(
Dates);return 0;}   //  Dive into dreams
