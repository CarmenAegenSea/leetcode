class Solution {
    public int maxProfit(int[] prices) {
        int minW = prices[0];
        int maxW = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < minW) minW = prices[i];
            else if (prices[i] - minW > maxW) maxW = prices[i] - minW;
        }
        return maxW;
    }
}
