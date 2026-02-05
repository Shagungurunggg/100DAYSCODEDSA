You are given an array prices where prices[i] is the price of a given stock on the ith day.You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &prices[i]);

    int min = prices[0], profit = 0;

    for(int i = 1; i < n; i++) {
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > profit)
            profit = prices[i] - min;
    }

    printf("%d", profit);

    return 0;
}

