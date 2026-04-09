int maxProfit(int* prices, int pricesSize) {
    int W = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] > prices[i - 1]) 
        W += prices[i] - prices[i - 1];
    }
    return W;
}