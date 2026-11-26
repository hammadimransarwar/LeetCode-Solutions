class Solution {
public:
    void calulate_subset(vector<int>&nums,vector<int>&temp,vector<vector<int>> &res,int index){
        if(index==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        calulate_subset(nums,temp,res,index+1);
        temp.pop_back();
        calulate_subset(nums,temp,res,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>> res;
        calulate_subset(nums,temp,res,0);
        return res;
    }
};