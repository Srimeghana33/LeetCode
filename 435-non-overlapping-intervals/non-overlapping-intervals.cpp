class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(arr.begin(),arr.end());
        int remove=0;
        int endtime=arr[0].first;

        for(int i=1;i<n;i++){
            if(arr[i].second<endtime){
                remove++;           //if overlap remove
            }
            else{
                endtime=arr[i].first;   //else keep the end time

            }
        }
        return remove;
    }
};