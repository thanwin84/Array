   # time: O(n) and space: O(1)
   def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        _min = float('inf')
        for i in range(len(prices)):
            if prices[i] < _min:
                _min  = prices[i]
            elif prices[i] > _min:
                profit = max(profit, prices[i] - _min)
        return profit
        
