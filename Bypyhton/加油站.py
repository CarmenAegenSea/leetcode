 

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        for i in range(len(gas)):
            cost[i] = gas[i] - cost[i]
        
        begin = 0
        while begin < len(cost):
            if cost[begin] < 0:
                begin += 1
                continue

            timeOil = 0
            for j in range(begin, begin + len(cost)):
                timeOil += cost[j % len(cost)]
                
                if timeOil < 0:
                    begin = j + 1
                    break
            else:
                return begin

        return -1
    