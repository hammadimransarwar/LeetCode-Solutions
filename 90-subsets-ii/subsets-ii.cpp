class Solution {
public:
    void cal_subset_dup(vector<int>& nums,vector<vector<int>> &r,vector<int> &temp,int index){
        if(index==nums.size()){
            r.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        cal_subset_dup(nums, r,temp,index+1);
        temp.pop_back();
        int idx=index+1;
        while(idx<nums.size()&&nums[idx] == nums[index]){
            idx++;
        }
        cal_subset_dup(nums, r,temp,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int index=0;
       vector<vector<int>> res;
       vector<int>temp;
       sort(nums.begin(), nums.end());
       cal_subset_dup(nums,res,temp,0);
       return res;

    }
};