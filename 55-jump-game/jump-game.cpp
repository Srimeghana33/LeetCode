class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
        for(int i=0;i<nums.size();i++){
            int jump=i+nums[i];
            if(i>maxindex){
                return false;
            }
            maxindex=max(maxindex,jump);
        }return true;
    }
};