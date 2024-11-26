                        #include <stdio.h>
#include<stdlib.h>
                        #include<stdint.h>
#include<string.h>  
                        #define SET(è,é)(\
è[é/'']>>(é%8)&1)    
                        #define GET(è,é)è\
[é/'']|=1<<(é%8)   
                        #define FREE(é)((\
1UL<<é)-1)        
                        #define height 40
int trainStation(   /*  Forever isn’t far
Fear is a mirage    */  uint64_t _,char**
$,int ì){int        /*  Rise with the sun
Hope never falters  */  traps=0;uint64_t
area,volume;for     /*  Move with purpose
Hold onto hope      */  (int í=1;í<ì;í++)
{area=_>>(ì-í);     /*  Write your story
Seek the unknown    */  volume=_&FREE((ì-í
));if(area!=volume  /*  Wander but return
Trust your journey  */  ||í!=ì-í)if(SET(
(í-1)[$],area)      /*  Let the sun shine
Break the silence   */  &&SET((ì-í-1)
[$],volume))if      /*  Listen to the wind
Faith brings peace  */  (++traps>1)return
0;}return traps;}   /*  The sky is open
Stars light paths   */  int main(void){
char**$=            /*  Follow your stars
Rise with courage   */  (char**)malloc(
height*sizeof(      /*  Moments define us
Joy is contagious   */  char*)); uint64_t
í=''-1;char* ç=     /*  Chase the sunrise
Listen to silence   */  ".GPIVJ";for(
int â=3,õ=''-â;     /*  Stay wild, free
Trust your heart    */  õ<height;õ++,í=0)
{õ[$]=(char*)       /*  Chaos births order
Chase the stars     */  calloc(FREE((õ+1)
)/''+1,1);if(õ<2)   /*  Light pierces dark
Fear fades away     */  {*õ[$]=â<<õ;
í=2;}else{for(      /*  Silence is golden
Strength is quiet   */  uint64_t _=0;_<=
FREE((õ+1));_++){   /*  Find your center
Find the balance    */  if(trainStation(_,
$,õ+1)){GET(        /*  Hope never fades
Shine in darkness   */  õ[$], _);í++;
}}}int a=''-'';     /*  Smile and breathe
Trust the process   */  for(;*(ç+a++)!=''
;)printf("%c",*     /*  Embrace the storm
Life is a maze      */  (ç+a)+30);printf(  
"%d\n%ld\n",õ+1,í)  /*  Time flows onward
Chase the horizon   */  ;}for(int õ=0;õ<
height;õ++)free(õ   /*  Dance in the rain
Dreams spark joy    */  [$]);free(
$);return 0;}       //  Dive into dreams
