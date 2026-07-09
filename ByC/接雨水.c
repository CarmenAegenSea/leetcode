#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int heightSize) {
	if (heightSize == 0) { return 0; }
	int* left = (int*)malloc(sizeof(int) * heightSize);
	int* right = (int*)malloc(sizeof(int) * heightSize);
	int left_highest = 0;
	for(int i = 0; i < heightSize; i++) {
		if (height[i] > left_highest) { left_highest = height[i]; }
		left[i] = left_highest;
	}
	int right_highest = 0;
	for(int i = heightSize - 1; i >= 0; i--) {
		if (height[i] > right_highest) { right_highest = height[i]; }
		right[i] = right_highest;
	}

	int sum = 0;
	for(int i = 0; i < heightSize; i++) {
		int min = left[i] < right[i] ? left[i] : right[i];
		sum += min - height[i];
	}

	free(left);
	free(right);
	return sum;
}
