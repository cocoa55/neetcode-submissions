class Solution {
public:
  vector<int> getConcatenation(vector<int>& nums) {


    vector<int> ans(nums.size() * 2); //create array of size 8

    size_t t{0};
    for (size_t i{0}; i < ans.size(); i++) {
      if (t == nums.size())  //this checks if t counter is at the limit, if it is, then reset it
        t = 0;
      
      ans[i] = nums[t]; //initialize each element with nums, problem here is that im trying to index nums[4] eventually which is out of bounds, so i think i need a seperate variable
    t++;
    }

    return ans;
  }
};