#User function Template for python3
class Solution:
	def countPairsWithDiffK(self,arr, k):
    	# code here
    	dict = {}
    	
    	for i in range(len(arr)):
    	   if arr[i] not in dict:
    	        dict[arr[i]]=1;
    	   else:
    	       dict[arr[i]]+=1;
    	       
    	
    	ans=0

    	for i in range(len(arr)):
    	    req = k+arr[i]
    	    
    	    if req in dict:
    	        ans+=dict[req]
    	        
    	return ans




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.countPairsWithDiffK(arr, k)
        print(ans)
        print("~")
        tc -= 1

# } Driver Code Ends