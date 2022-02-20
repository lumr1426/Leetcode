class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        for i in range(len(prices)-1):
            j=i+1
            for j in range(j,len(prices)):
                if prices[i]>=prices[j]:
                    prices[i]-=prices[j]
                    break
        return prices
