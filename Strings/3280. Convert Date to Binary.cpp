
    /*
    Time complexity : O(LogN)
    Space complexity : O(LogN)
    */


class Solution {
private:
    string binaryConversion(int num){
        if (num == 1)
            return to_string(1);
        string bin = "";
        while (num){
            bin = to_string(num % 2) + bin;
            num /= 2;
        }
        return bin;
    }
public:
    string convertDateToBinary(string date) {
        string year = binaryConversion(stoi(date.substr(0, 4)));
        string month = binaryConversion(stoi(date.substr(5, 2)));
        string day = binaryConversion(stoi(date.substr(8, 2)));
        return year + "-" + month + "-" + day;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/convert-date-to-binary/description/
    */

    