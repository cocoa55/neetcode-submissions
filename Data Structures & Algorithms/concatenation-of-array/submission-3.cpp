class Solution {
public:
  vector<int> getConcatenation(vector<int>& nums) {

    size_t length {nums.size()};

    vector<int> ans = nums;
    ans.insert(ans.end(), nums.begin(), nums.end());
    return ans;
  }
};