#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

//edanglobus

class Solution {

public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, std::vector<int>> ind_by_val = {}; // Creating an Ordered map containing first=nums[], second=vector of indices
        bool found = false; // flag 
        auto key_itr = ind_by_val.begin(); // init key_itr

        // Passing on the vector nums
        for (int ind = 0; ind < nums.size() && found == false; ++ind) {
            key_itr = ind_by_val.find(target - nums[ind]);// searching for the target's complement
         
            if (key_itr == ind_by_val.end()) { 
                ind_by_val[nums[ind]].push_back(ind); // if didnt found complement then add to map value as a key push back indice
            }
            else {
                key_itr->second.push_back(ind); // else found target's complement then push it back to complement key value
                found = true;
            }
        }

        if (found)
            return key_itr->second;
    }
};



int main() {
    Solution one;
    std::vector<int> nums = { 5,6,10,2,1,-5,3 };
    int target = 10;

    std::vector<int> res = one.twoSum(nums, target);

    for (int val : res) {
        std::cout << nums[val] << std::endl;
    }

    return 0;
}