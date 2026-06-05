int digitFrequencyScore(int n) {
    int sum = 0;
    for (; n > 0;) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}