
    /*
    Time complexity : O(max(m,n))
    Space complexity : O(max(m,n))
    */


class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        char carry = '0';

        if(b.size() > a.size())
        {
            string temp = b;
            b = a;
            a = temp;
        }

        int i = a.size() - 1 , j = b.size() - 1;
        while((i >= 0) && (j >= 0))
        {
            if(a[i] == '1' && b[j] == '1')
            {
                if(carry == '0') result += '0';
                if(carry == '1') result += '1';
                carry = '1';
            }

            if((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1'))
            {
                if(carry == '0') result += '1';
                if(carry == '1') 
                {
                    result += '0';
                    carry = '1';
                }
            }

            if(a[i] == '0' && b[j] == '0')
            {
                if(carry == '0') result += '0';
                if(carry == '1') result += '1';
                carry = '0';
            }

            i--;
            j--;
        }

        if(a.size() > b.size())
        {
            while(i >= 0)
            {
                if(carry == '1' && a[i] == '1') result += '0';
                else if(carry == '1' && a[i] == '0')
                {
                    result += '1';
                    carry = '0';
                } 
                else if(carry == '0') result += a[i];
                i--;
            }
        }

        if(carry == '1') result += '1';
        reverse(result.begin() , result.end());
        return result;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/add-binary
    */

    