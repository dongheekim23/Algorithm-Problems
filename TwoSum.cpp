// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
vector<int> twoSum(vector<int>& nums, int target) 
{        
    vector<int> result;
    bool breakLoop = false;

    for(int i = 0; i < nums.size() - 1; ++i)
    {            
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                result.emplace_back(i);
                result.emplace_back(j);

                breakLoop = true;
                break;
            }
        }
        if(breakLoop)
            break;
    }

    return result;
}
