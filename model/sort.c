// 排序 (Sorting)
// 用途: 快速排序 / 归并排序 / qsort 封装
// 归并排序可同时用于求逆序对

#include <stdlib.h>

#define MAXN 100010

// qsort 比较函数 (升序)
int cmp_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// qsort 封装
void sort_int(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_int);
}

// 快速排序 (适用于竞赛手写)
void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = arr[(l + r) / 2];
    while (i < j) {
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if (i < j) { int t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}

// 归并 (合并两个有序区间)
void merge(int arr[], int tmp[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = tmp[i];
}

// 归并排序
void merge_sort(int arr[], int tmp[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(arr, tmp, l, mid);
    merge_sort(arr, tmp, mid + 1, r);
    merge(arr, tmp, l, mid, r);
}
