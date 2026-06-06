// 计算数字 n 的各位数字之和
int digitFrequencyScore(int n) {
    int sum = 0;
    for (; n > 0;) {
        sum += n % 10;  // 取最低位
        n /= 10;        // 移除最低位
    }
    return sum;
}