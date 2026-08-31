class Solution {
public:
  vector<int> getConcatenation(vector<int>& nums) {

    size_t length {nums.size()};

    vector<int> ans(length * 2); 

    for(size_t i{0}; i < length; i++){
        ans[i] = nums[i];
        ans[i + length] = nums[i];
    }
    return ans;
  }
};