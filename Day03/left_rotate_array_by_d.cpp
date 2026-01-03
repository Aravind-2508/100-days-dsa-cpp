// Problem Link: https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int d = k%nums.size();
        reverse(nums.begin(), nums.end()-d);
        reverse(nums.end()-d,nums.end());
        reverse(nums.begin(),nums.end());
        
        
    }
};