#include <stdio.h>
#include <stdlib.h>

// 检测是否有阻挡 
void Pain(int* nums, int numsSize, int* lastHeight, int k) {
	for (int i = 0; i < numsSize; i++) {
		if (lastHeight[i] > k) {
			nums[i]++;
		}
	}
}

int trap(int* height, int heightSize) {
	int HIGETH = 0;
	for (int i = 0; i < heightSize; i++) {
		if (height[i] > HIGETH) {
			HIGETH = height[i];
		}
	}
	
	int WATERBOTTOR = 0;
	for (int k = 0; k < HIGETH; k++) {
		int* heightPain = (int*)calloc(heightSize, sizeof(int));
		Pain(heightPain, heightSize, height, k);
		
		int LAST = 0; // 第一点 
		int NEXT = 1; // 第二点 
		int FIRST = 1;// 当前为第几点 
		for (int i = 0; i < heightSize; i++) {
			if (heightPain[i] != 0 && FIRST == 1) {
				LAST = i;
				FIRST++; 
			} else if (heightPain[i] != 0 && FIRST == 2) {
				NEXT = i;
                WATERBOTTOR += NEXT - LAST - 1;
                LAST = NEXT;
			}
		}
		free(heightPain);
	}
	
	return WATERBOTTOR;
}


int main() {
	int h1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int h2[] = {4,2,0,3,2,5};
	int h3[] = {2,0,2};
	printf("%d %d %d\n", trap(h1, 12), trap(h2, 6), trap(h3, 3));
	return 0;
}