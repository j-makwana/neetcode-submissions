# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        result=[]
       
        for i in range(1, len(pairs)):
            j = i-1
                    
            result.append(pairs[:])
            while j>=0 and pairs[j+1].key < pairs[j].key:
                temp= pairs[j+1]
                pairs[j+1]= pairs[j]
                pairs[j]= temp
                j-=1
        if len(pairs) != 0:     
            result.append(pairs[:])

        return result
                
        