#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define q 16
#define o(x) ((1U<<x)-1)
#define u uint64_t
#define d int
#define y(i,x,r) for(d i=x;i<r;i++)
#define _ NULL
#define z(x) return x;
#define w(x,y) while(x){y}
typedef struct N{struct N*f;u v;}N;
typedef struct{N* h;N* t;d s;}W;
void a(W* l,u v){N* n=(N*)malloc(sizeof(N));n->v=v;n->f=_;if(l->h==_)l->h=n,l->t=n;else l->t->f=n,l->t=n;l->s++;}
void c(W* l){N* n=l->h;w(n,N* f=n->f;free(n);n=f;)l->h=_,l->t=_,l->s=0;}
d í(u ´,W* l){N* n=l->h;w(n!=_,if(n->v==´)z(1)n=n->f;)z(0)}
d k(u ´,W* o,d l){d r=0;u _w,w;y(i,1,l){_w=´>>l-i;w=´&o(l-i);if(_w!=w||i!=l-i)if(í(_w,&o[i-1])&&í(w,&o[l-i-1]))if(++r>1)z(0)}z(r)}
d main(){W* o=malloc(q*sizeof(W));y(i,0,q){o[i].h=_;o[i].t=_;o[i].s=0;}
y(i,0,2)a(&o[0],i),a(&o[1],i+1);y(i,2,q){y(e,0,o(i+1)+1){if(k(e,o,i+1))a(&o[i],e);};}
FILE*fp=fopen("w","w");y(i,0,q)fprintf(fp,"Length %d\n%d\n",i+1,o[i].s);fclose(fp);y(i,0,q)c(&o[i]);free(o);z(0)}