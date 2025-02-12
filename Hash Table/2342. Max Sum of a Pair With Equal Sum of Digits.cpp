class Solution {
public:

    int sum_of_digits(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums)
    {
        int result = -1;
        unordered_map<int,vector<int>> sum_to_pair;

        for(int i : nums)
        {
            int digit_sum = sum_of_digits(i);
            if(sum_to_pair[digit_sum].size() == 2)
            {
                sum_to_pair[digit_sum][0] > sum_to_pair[digit_sum][1] ? sum_to_pair[digit_sum][1] = i : sum_to_pair[digit_sum][0] = i;
            }
            else sum_to_pair[digit_sum].push_back(i);

            if(sum_to_pair[digit_sum].size() == 2) 
            {
                result = max(result , (sum_to_pair[digit_sum][0] + sum_to_pair[digit_sum][1]));
            }
        }

        return result;
    }
};
