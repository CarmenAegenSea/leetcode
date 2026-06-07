#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
		
		int LAST = 0;
		int NEXT = 1;
		int FIRST = 1;
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
	printf("%d ", trap(h1, 12));
	int h2[] = {4,2,0,3,2,5};
	printf("%d\n", trap(h2, 6));
	return 0;
}
