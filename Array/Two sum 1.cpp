/*
 
 link: https://leetcode.com/problems/two-sum/
   
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

we find the  index two nof umber  that sum equal to target.but once you  think  this way you have to find a first number index that equal to (target-second number).

# Approach
<!-- Describe your approach to solving the problem. -->
we find a first  number index that is equal to target-second number.
then we think about map .we store the value and index in a map. first we  search  an element in a map (target-second number) if we find that we find the index of it and return the search number index and current index. if we can not find this in map then we simply insert in a map.

 approach : num[i] = target-nums[j]

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
insertion in a map is o(1) but we iterate over the vector then Time complexity : O(n) , n: number of element

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
we use a map and insert element in it . space complexity: O(n),n:number of element

# Code
```*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       map<int,int>mp;

        for(int i=0;i<nums.size();i++){    
              int ele=target-nums[i];
              if(mp.find(ele)!=mp.end()) return {mp[ele],i}; 
            //   mp[nums[i]]=i;
              mp.insert({nums[i],i});
        }

         return {-1,-1};
          
    }
};
