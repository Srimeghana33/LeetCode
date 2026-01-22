class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;

        int count=0;
        while(r<nums.size()-1){
            int maxindex=0;
            for(int i=l;i<=r;i++){
                int jump=i+nums[i];
                maxindex=max(jump,maxindex); 

            }
            l=r+1;
            r=maxindex;
            count++;
        }
        return count;
    }
};