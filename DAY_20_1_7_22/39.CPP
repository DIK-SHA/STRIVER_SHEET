// 3 SUM , A[i]+A[j]+A[k]==0

class Solution {
public:

//2 loop aur fir x find krne k liye binary search--------------------------------------------------------------------------

    // bool bs(vector<int> arr, int si, int ei, int x){
    //     if(si>ei)
    //         return false;
    //     while(si<=ei){
    //         int mid=(si+ei)>>1;
    //         if(arr[mid]==x)
    //             return true;
    //         else if(arr[mid]<x)
    //             si=mid+1;
    //         else 
    //             ei=mid-1;
    //     }
    //     return false;
    // }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> v;
    //     set<vector<int>> s;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             int x=0-nums[i]-nums[j];
    //             if(bs(nums, j+1, n-1, x)){
    //                 s.insert({nums[i],nums[j],x});
    //             }
    //         }
    //     }
    //     for(auto i:s){
    //         v.push_back(i);
    //     }
    //     return v;
    // }
    
//1 loop aur fir two pointer approach to find next 2 numbers----------------------------------------------------------------
     vector<vector<int>> threeSum(vector<int>& nums){
         vector<vector<int>> v;
         set<vector<int>> s;
         sort(nums.begin(), nums.end());
         int n=nums.size();
         for(int i=0;i<n;i++){
             int x=i+1;
             int y=n-1;
             while(x<y){
                 if(nums[x]+nums[y]+nums[i]==0)
                 {
                     s.insert({nums[i], nums[x], nums[y]});
                     x++;
                     y--;
                 }
                 else if(nums[x]+nums[y]+nums[i]<0)
                     x++;
                 else
                     y--;
             }
         }
         for(auto i:s){
             v.push_back(i);
         }
         return v;
     }
};


// description ke achhe codes ---------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
            int sum = 0;
            while(low < high){                          //Search between two pointers, just similiar to binary search.
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                    high--;
                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                    low++;
                } else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(low < high && nums[low] == last_low_occurence){   // Update the low and high with last occurences of low and high.
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};


//description solution ----------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());     //Sorted Array
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        unordered_map<int , int> hashMap;
        for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
            hashMap[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};