int maxProfit(int* prices, int pricesSize) {
    int minW = prices[0]; //假设最低价格
    int maxW = 0; //假设最大利润

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minW) minW = prices[i]; //如果比当前最低价格还低，就更新最低价格
        else if (prices[i] - minW > maxW) maxW = prices[i] - minW; //如果当前价格减去最低价格的利润比当前最大利润还大，就更新最大利润
    }

    return maxW;
}