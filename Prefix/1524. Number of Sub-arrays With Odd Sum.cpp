class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int curr_sum = 0 , even_sum_count = 0 , odd_sum_count = 0;
        int result = 0 , mod = 1e9 + 7;
        for(int i : arr)
        {
            curr_sum += i;
            if(curr_sum % 2 == 0)
            {
                result += odd_sum_count;

                even_sum_count += 1; 
            } 
            else
            {
                result += 1;
                result += even_sum_count;

                odd_sum_count += 1;
            }
            result %= mod;
        }
        return result;        
    }
};
