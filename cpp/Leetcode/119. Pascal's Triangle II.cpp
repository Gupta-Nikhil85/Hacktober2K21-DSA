// Question URL:- https://leetcode.com/problems/pascals-triangle-ii/
// Github:- Gupta-Nikhil85

class Solution {
public:
    vector<int> getRow(int numRows) {
        if(numRows==0) return{1};
        vector<int> arr= {{1,1}};
        for(int i=2; i<=numRows; i++){
            int temp= arr[0];
            for(int j=1; j<i; j++){
                int temp_j= arr[j];
                arr[j]= temp+arr[j];
                temp=temp_j;
            }
            arr.push_back(1);
        }
        return arr;
    }
};