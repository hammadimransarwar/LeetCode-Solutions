class Solution {
public:
    void get_suitable_candiadates(vector<int>&candiadtes,int target,vector<int>&temp,vector<vector<int>>&res,int index,int sum){
        if(sum>=target||index==candiadtes.size()){
            if(sum==target) res.push_back(temp);
            return;
        }
        temp.push_back(candiadtes[index]);
        get_suitable_candiadates(candiadtes,target,temp,res,index,sum+candiadtes[index]);
        temp.pop_back();
        get_suitable_candiadates(candiadtes,target,temp,res,index+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int>temp;
        vector<vector<int>> res;
        get_suitable_candiadates(candidates,target,temp,res,index,0);
        return res;
    }
};