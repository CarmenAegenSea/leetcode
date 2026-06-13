#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int b, e, t;
}Nums;

int cmp(const void* a, const void* b) {
    return ((Nums*)a)->e - ((Nums*)b)->e;
}
 
int main() {
	int n;
	scanf("%d", &n);
	int h;
	scanf("%d", &h);
	Nums nums[30005];
	for(int i = 0; i < h; i++) {
		scanf("%d %d %d", &nums[i].b, &nums[i].e, &nums[i].t);
	} 

    qsort(nums, h, sizeof(Nums), cmp);

    int tree[30005] = {0};
    for(int i = 0 ; i < h; i++) {
        int T = nums[i].t;
        int thisT = 0;
        int last = nums[i].b;
        int next = nums[i].e;
        for(int j = last; j <= next; j++) {
            if (tree[j] == 1) {
                thisT++;
            }
        }
        if (thisT != T) {
            while(thisT < T) {
                if (tree[next] != 0) {
                next--;
                } else {
                    tree[next]++;
                    thisT++;
                }
            }
        } 
    }

    int T = 0;
    for(int i = 0; i < n + 2; i++) {
        if (tree[i] != 0) T++;
    }
    printf("%d", T);
	return 0;
} 