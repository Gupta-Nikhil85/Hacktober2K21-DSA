//https://leetcode.com/problems/k-closest-points-to-origin/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(int i=0;i<points.size();i++)
        {
            int f=points[i][0];
            int s=points[i][1];
            int sq=f*f+s*s;
            maxh.push({sq,{f,s}});
        
        
        if(maxh.size()>k)
        {
            maxh.pop();
        }
        }
        
        while(maxh.size()>0)
        {
            pair<int, pair<int,int>> temp = maxh.top();
            res.push_back({(temp.second).first, (temp.second).second});
            maxh.pop();
            
        }
        
        return res;
        
    }
};
