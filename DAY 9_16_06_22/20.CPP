//4Sum
class Solution {
public:
    // bool binarysearch(vector<int>& v, int si, int ei, int x){
    //     if(si>ei)
    //         return false;
    //     int mid;
    //     while(si<=ei){
    //         mid=(si+ei)>>1;
    //         if(v[mid]==x)
    //             return true;
    //         else if(v[mid]<x)
    //             si=mid+1;
    //         else
    //             ei=mid-1;
    //     }
    //     return false;
    // }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        //if(nums[0]>target)
          //  return res;
         set<vector<int>> s;
         if(nums.size()==0)
             return res;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long z=(long)target-(long)nums[i]-(long)nums[j];
                int x=j+1;
                int y=nums.size()-1;
                while(x<y){
                    if(nums[x]+nums[y]==z)
                    {
                        s.insert({nums[i], nums[j], nums[x], nums[y]});
                        x++,y--;
                    }
                    else if(nums[x]+nums[y]<z)
                        x++;
                    else
                        y--;
                }
            }
        }
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             int x=target-nums[i]-nums[j]-nums[k];
        //             if(binarysearch(nums,k+1,nums.size()-1,x))
        //             {
        //                 s.insert({nums[i],nums[j], nums[k], x});
        //             }
        //         }
        //     }
        // }
        
         for(auto i:s)
         {
             res.push_back(i);
         }
         return res;
    }
};

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]