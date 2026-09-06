class Solution {
public:
    // Brute or Better
    // void helper(vector<int>& nums,vector<vector<int>>& ans, vector<int>& temp,int freq[]) {
    //     if(temp.size()==nums.size()) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++) {
    //         if(!freq[i]) {
    //             temp.push_back(nums[i]);
    //             freq[i]=1;
    //             helper(nums,ans,temp,freq);
    //             freq[i]=0;
    //             temp.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     int freq[nums.size()];
    //     for(int i=0;i<nums.size();i++) {
    //         freq[i]=0;
    //     }
    //     helper(nums,ans,temp,freq);
    //     return ans;   
    // }

    // Optimal
    void helper(int ind,vector<int>& nums,vector<vector<int>>& ans) {
        if(ind==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            swap(nums[ind],nums[i]);
            helper(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;   
    }
};