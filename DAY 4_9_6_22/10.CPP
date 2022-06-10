//FIND REPEATING ELEMENTS IN ARRAY
    int findDuplicate(vector<int>& arr) {
        //you cant sort array as you cant modify array
        //BRUTE FORCE
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]=nums[i+1])
                return nums[i];
        }
        return -1;
        
        //BINARY SEARCH APPROACH
        int si=1,ei=nums.size()-1;
        int mid;
        while(si<=ei){
            mid=(si+ei)>>1;
            int cnt=0;
            for(auto n:nums){
                if(n<=mid)
                    cnt++;
            }
            if(cnt<=mid)
                si=mid+1;
            else
                ei=mid-1;
        }
        return si;
        
        //STRIVER WAALI APPROACH
        int slow=arr[0];
        int fast=arr[0];
        do{
            slow=arr[slow];
            fast=arr[arr[fast]];
        }while(slow!=fast);
        fast=arr[0];
        while(slow!=fast){
            fast=arr[fast];
            slow=arr[slow];
        }
        return slow;
    }