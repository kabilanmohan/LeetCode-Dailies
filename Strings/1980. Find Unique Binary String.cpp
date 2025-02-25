class Solution {
public:
    // Cantor's diagonalization
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        string result(n , 'a');

        int ptr = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i][ptr] == '0') result[ptr] = '1';
            else result[ptr] = '0';

            ptr++;
        }

        return result;
    }
};
