using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) { //target is 7, [3, 4, 5, 6]
    unordered_map<int, int> map;

    for (int i{}; i < nums.size(); i++) {
      int complement {target - nums[i]}; //7 - 3, = 4.

      if(map.contains(complement)){ //if the map contains the current complement, then we can return the complements index, aswell as our current index in the loop
        return {map[complement], i};
      } else {
        map[nums[i]] = i; //map the index with the value
      }
    }
  }
};