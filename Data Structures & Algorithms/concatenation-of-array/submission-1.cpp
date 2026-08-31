class Solution {
public:
  vector<int> getConcatenation(vector<int>& nums) {


    vector<int> ans; //create array of size 8

    for(size_t i{0}; i < 2; i++){

        for(auto& e: nums) //e should be 1, 
            ans.push_back(e); //we should append e into ans.
    }

    return ans;
  }
};