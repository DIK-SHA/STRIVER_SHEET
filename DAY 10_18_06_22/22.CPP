// Largest subarray with 0 sum
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> mp;
        int res=0;
        int currsum=0;
        for(int i=0;i<n;i++){
            
            currsum+=A[i];
            if(currsum==0){
                res=max(res,i+1);
            }
            if(mp.find(currsum)!=mp.end()){
                res=max(res,i-mp[currsum]);
            }
            else{
                mp[currsum]=i;
            }
        }   
        return res;
    }
};

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.