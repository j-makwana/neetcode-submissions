# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        s = 0
        e= len(pairs)-1
        def merger(arr, s, e):
            if e-s+1 <=1:
                return arr
            
            m = (e+s)//2
            merger(arr,s,m)
            merger(arr,m+1, e)

            mergeArray(arr,s,m,e)
            return arr

        def mergeArray(arr,s,m,e):
            L = arr[s:m+1]
            R = arr[m+1:e+1]

            i = 0
            j = 0
            k = s
            while i<len(L) and j<len(R):
                if L[i].key<=R[j].key:
                    arr[k]=L[i]
                    i+=1
                else:
                    arr[k]= R[j]
                    j+=1
                k+=1
            while i<len(L):
                arr[k]= L[i]
                i+=1
                k+=1
            while j<len(R):
                arr[k]= R[j]
                j+=1
                k+=1
            
        return merger(pairs,s,e)
            


                




