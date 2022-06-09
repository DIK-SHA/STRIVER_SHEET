//MERGE SUBINTERVALS
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        if(intervals.size()<=1){
            return intervals;
        }
        //SORT THE ARRAY
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        //COMPARE AND PUSH
        for(int i=1;i<intervals.size();i++){
            if(v.back()[1]>=intervals[i][0])
                v.back()[1]=max(v.back()[1],intervals[i][1]);
            else
                v.push_back(intervals[i]);
        }
        return v;
    }

//[1,4][0,3] = [0,4]
//[1,4][4,8] =[1,8]
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].