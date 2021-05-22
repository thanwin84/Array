class Solution:
    
    # arr[] : the input array
    # N : size of the array arr[]
    
    #Function to return length of longest subsequence of consecutive integers.
    def findLongestConseqSubseq(self,arr, N):
        #code here
        lookup = {}
        total = 0
        result = float('-inf')
        for i in range(N):
            if arr[i] not in lookup:
                lookup[arr[i]] = 1
            else:
                lookup[arr[i]] = 1
        for i in range(N):
            if arr[i] - 1 in lookup:
                continue
            else:
                count = 0
                item = arr[i]
                while True:
                    if item in lookup:
                        count += 1
                    else:
                         break
                    item += 1
                total += count
                if count > result:
                    result = count
            if total > N:
                break
        return result
