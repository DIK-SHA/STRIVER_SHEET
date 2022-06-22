// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //THE CODE WRITTEN BELOW WILL NOT WORK FOR "abcdeafghij" , its answer must be 10 .
        // int maxi=0,cnt=0;
        // for(int i=0;i<s.size();i++){
        //     map<char,int> mp;
        //     while(i<s.size() && mp.find(s[i])==mp.end())
        //     {
        //         cnt++;
        //         mp[s[i]]++;
        //         i++;
        //     }
        //     maxi=max(cnt,maxi);
        //     cnt=0;
        // }
        // return maxi;
        
        int r=0,l=0;
        map<char,int> mp;
        int maxi=0,cnt=0;
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end() && (mp[s[r]]<=r && mp[s[r]]>=l)){
                l=mp[s[r]]+1;
            }
            maxi=max(maxi, r-l+1);
            mp[s[r]]=r;
            r++;
        }
          return maxi;  
    }
};
// Input: s = ”abcabcbb”
// Output: 3
// Explanation: The answer is abc with length of 3.

// Input: s = ”bbbbb”
// Output: 1
// Explanation: The answer is b with length of 1 units.