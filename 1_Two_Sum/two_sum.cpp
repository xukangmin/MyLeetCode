#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    // brutal force, check all posibilities

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for(int i = 0; i < nums.size();i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums.at(i) + nums.at(j) == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
        
    }


    // use hash map, 1. put into map first, then check target - num[i] to see matches
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            map.insert(make_pair(nums.at(i),i));
        }

        for(int i = 0; i < nums.size(); i++) {
            int res = target - nums.at(i);
            if (map[res] != i && (map[res] != 0 || (map[res] != i && map[res] == 0 && nums.at(map[res]) == res))) {
                result.push_back(i);
                result.push_back(map[res]);
                return result;
            }
        }

        return result;
        
    }

    // Use hash map 
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> result;

        unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[target - nums[i]] = i;
            } else {
                result.push_back(m[nums[i]]);
                result.push_back(i);
                return result;
            }

        }


        return result;
    }
    
};

int main() {
    Solution a;

    int arr[] = { 3, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    vector<int> vect(arr, arr + n); 

    int target = 6;

    vector<int> ret;
    ret = a.twoSum2(vect, target);

    cout << "[";
    for(auto x : ret)
        cout << x << " ";

    cout << "]" << endl;

    return 0;
}
