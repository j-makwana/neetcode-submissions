# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        s,e = 0, len(pairs)-1
        def quickSorter(arr, s, e):
            
            if e-s +1<=1:
                return arr
            ##arranging as you go down
            # choose pivot
            pivot = pairs[e]
            left= s
            for i in range(s,e):
                if arr[i].key<pivot.key:
                    temp=arr[left]
                    arr[left]= arr[i]
                    arr[i]= temp
                    left+=1
            ##last witch pivots
            arr[e]= arr[left]
            arr[left]= pivot
            quickSorter(arr, s, left-1)
            quickSorter(arr, left+1, e)
            return arr
        return quickSorter(pairs, s, e)


            


        