# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        s,e = 0, len(pairs)-1
        def quickSorter(arr, s, e):
            if e-s+1<=1:
                return arr
            
            pivot= arr[e].key
            left= s
            for i in range(s,e+1):
                if arr[i].key < pivot:
                    temp= arr[left]
                    arr[left]= arr[i]
                    arr[i]= temp
                    left +=1
            ##change pivots
            newPivot = arr[left]
            arr[left] = arr[e]
            arr[e]= newPivot

            quickSorter(arr, s, left-1)
            quickSorter(arr,left+1, e)
            return arr
        return quickSorter(pairs, s,e)


            


        