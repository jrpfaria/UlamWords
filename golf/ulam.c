#include <stdio.h>
#include <stdlib.h>
#define b(p,x)p[x/8]>>(x%8)&1
#define s(p,x)p[x/8]|=1<<(x%8)
#define o(x)((1UL<<(x))-1)
#define L unsigned long
int main(void){char**p=(char**)malloc(30*8);FILE*fp=fopen("w","w");L S=0;for(L i=0,j=3;i<30;i++,S=0){p[i]=(char*)malloc(o(i+1)/8+1);if(i<2)*p[i]=j<<i,S=2;else for(L w=0,t=i+1,r=0,h,l;w<=o(i+1);w++,r=0){for(L k=1;k<t;k++){h=w>>(t-k);l=w&o(t-k);if(h!=l||k!=t-k)if(b(p[k-1],h)&&b(p[t-k-1],l))if(++r>1)break;}if(r==1)s(p[i],w),S++;}fprintf(fp,"Length %ld\n%ld\n",i+1,S);}for(L i=0;i<30;i++)free(p[i]);free(p);fclose(fp);return 0;}