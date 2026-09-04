class Solution {
public:
    void helper(int ind, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp, int sum) {
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            if(i!=ind && nums[i]==nums[i-1])
            continue;
            if(sum+nums[i]<=target) {
                sum+=nums[i];
                temp.push_back(nums[i]);
                helper(i+1,nums,target,ans,temp,sum);
                sum-=nums[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        helper(0,candidates,target,ans,temp,sum);
        return ans;
    }
};