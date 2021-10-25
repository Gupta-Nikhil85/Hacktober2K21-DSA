class Solution {
public:

vector<int> twoSum(vector<int>& nums, int target) {
  
    int n = nums.size();
  
    //{val,idx}
    unordered_map<int,int> m;
    
    for(int i = 0 ; i < n ; i++){
        if(m.find(target-nums[i]) !=m.end()){
            auto it = m.find(target-nums[i]);
            return {i,it->second};
        }else{
            m[nums[i]] = i;
        }
    }
    return {-1,-1};
}
};
