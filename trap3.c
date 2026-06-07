#include <stdio.h>
#include <stdlib.h>
void Pain(int* n, int s, int* h, int k) { for(int i=0;i<s;i++) if(h[i]>k) n[i]++; }
int trap(int* h, int s) {
    int mx=0; for(int i=0;i<s;i++) if(h[i]>mx) mx=h[i];
    int w=0;
    for(int k=0;k<mx;k++) {
        int* p=(int*)calloc(s,sizeof(int)); Pain(p,s,h,k);
        int L=0,F=1;
        for(int i=0;i<s;i++) if(p[i]) { if(F==1) L=i,F++; else w+=i-L-1,L=i; }
        free(p);
    }
    return w;
}
int main(){int h[]={2,0,2};printf("%d\n",trap(h,3));}
