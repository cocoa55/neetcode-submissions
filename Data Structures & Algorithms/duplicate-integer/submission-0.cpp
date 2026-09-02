class Solution {
public:
  bool hasDuplicate(std::vector<int>& nums) {

    std::unordered_map<int, int> map;

    for (int i{0}; i < nums.size(); i++) {

      if (map.contains(nums[i])) //if the map contains the number
        return true;  //return true
      else
        map[nums[i]] = i; 
    }
  return false;
  }

};