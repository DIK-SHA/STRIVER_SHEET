// REVERSE PAIRS -> INVERSION COUNT JAISA HAI -> MERGE SORT USE HOGA
class Solution {
public:
    int merge(vector<int> &v, int si, int ei){
        vector<int> temp;
        int mid=(si+ei)>>1;
        int count=0;
        int i=si,j=mid+1;
        while(i<=mid){// ISKI TIME COMPLEXITY O(N) HOGI
            while(j<=ei&& !(v[i]<=(long) 2*v[j])){
                j++;
            }
            count+=j-mid-1;
            i++;
        }
        //DONT THE ABOVE WHILE LOOP AND THE BELOW WHILE LOOP , ONLY USE THIS ONE -> 
        //TOH BHI HOO JAYEGA KAAM BS YE WALA SOLUTION TLE DE RHA HAI
        // while(i<=mid && j<=ei){
        //     if(v[i]<v[j]){
        //         temp.push_back(v[i]);
        //         i++;
        //     }
        //     else{
        //         temp.push_back(v[j]);
        //         int x=i;
        //         while(x<=mid){
        //             if(v[x]>(long) 2*v[j])
        //                 count++;
        //             x++;
        //         }
        //         j++;
        //     }
        //}
        i=si;
        j=mid+1;
         while(i<=mid && j<=ei){
            if(v[i]<v[j]){
                temp.push_back(v[i]);
                i++;
            }
            else{
                temp.push_back(v[j]);
                j++;
            }
        }
    
        while(i<=mid){
            temp.push_back(v[i]);
            i++;
        }
        while(j<=ei){
            temp.push_back(v[j]);
            j++;
        }
        for(auto i:temp){
            v[si]=i;
            si++;
        }
        return count;   
    }
    
    int pairs(vector<int>& v, int si, int ei){
        if(si>=ei)
            return 0;
        int mid=(si+ei)>>1;
        return pairs(v, si, mid)+pairs(v, mid+1, ei)+merge(v, si,ei);
    }
    
    
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        return pairs(nums, 0, nums.size()-1);
    }
};


//OVERALL TIME COMPLEXITY IS O(NlogN)+O(N)+O(N) -> FOR SORTING, COUNTING AND MERGE OPERATION
// SPACE COMPLEXITY = O(N)

//40 25 19 12 9 6 2
//OP-> 15
