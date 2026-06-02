// 二分查找 (Binary Search)
// 用途: 在有序数组中快速定位元素 / 求边界
// lower_bound: 第一个 >= x 的位置
// upper_bound: 第一个 > x 的位置
// binary_search: 判断 x 是否存在

// 返回第一个 >= x 的元素下标 (范围 [0, n])
int lower_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

// 返回第一个 > x 的元素下标 (范围 [0, n])
int upper_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l;
}

// 标准二分查找, 找到返回下标, 否则返回 -1
int binary_search(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
