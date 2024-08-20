/*
	Assignment: You are given an array prices where prices[i] is the price of a given stock on the ith day.

	You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

	Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

int maxProfit(int* prices, int pricesSize) {
    int cheaperPrice;
    int maxProfit;

	// If the array has 0 or 1 element, there is no need to buy and sell.
    if (pricesSize < 2) {
        return 0;
    }
	
    cheaperPrice = prices[0];
    maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (cheaperPrice > prices[i])
            cheaperPrice = prices[i];
        else if (prices[i] - cheaperPrice > maxProfit)
            maxProfit = prices[i] - cheaperPrice;
    }
    return maxProfit;
}