class Solution {
public:
    // method1:-

    // vector<int> twoSum(vector<int>& nums, int target) {
    //      unordered_map<int,int>mp;
    //     pair<int,int>ans;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]=i;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         int other=target-nums[i];
    //         if(mp.find(other) != mp.end()&& mp[other] != i){
    //             return {i,mp[other]};
    //         }
    //     }
    //     return {};
    // }

    // method 2:-
    vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){

        int other = target - nums[i];

        if(mp.find(other) != mp.end()){
            return {mp[other], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

};

