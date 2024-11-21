#include <stdio.h>
#include <stdlib.h>
#define b(y,x)p[y][x/8]>>(x%8)&1
#define o(x)((1UL<<(x))-1)
#define L unsigned long
int main(void){char*p[40];L S=0;for(L i=0;i<40;i++,S=0){p[i]=(char*)malloc(o(i+1)/8+1);if(i<2)*p[i]=3<<i,S=2;else for(L w=0,t=i+1,r=0,h,l;w<=o(i+1);w++,r=0){for(L k=1;k<t;k++){h=w>>(t-k);l=w&o(t-k);if(h^l||k^t-k)if(b(k-1,h)&&b(t-k-1,l))if(r++)break;}if(r==1)p[i][w/8]|=1<<(w%8),S++;}printf("Length %ld\n%ld\n",i+1,S);}for(L i=0;i<40;i++)free(p[i]);return 0;}