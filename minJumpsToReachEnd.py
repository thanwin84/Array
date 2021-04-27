class Solution:
    def minJumps(self, arr, n):
        # if arr size is 1, we need 0 jumps
        if len(arr) == 1:
            return 0
        # if arr[0] = 0, we cannot jump to anywhere
        #cause our ladder size is 0
        if arr[0] == 0:
            return -1
        ladder = arr[0]
        stairs = arr[0]
        jumps = 1
        for step in range(1, n):
            # if our current step is equal to n -1, we dont need to use new ladder
            if step == n -1:
                return jumps
            # if we can construct a new ladder, construct it
            if step + arr[step] > ladder:
                ladder = arr[step] + step
            stairs -= 1
            if stairs == 0:
                jumps += 1
                # if step is equal to ladder size, we dont have stairs left to jump to new element
                if step == ladder:
                    return -1
                # set new stairs
                stairs = ladder - step
        return jumps
