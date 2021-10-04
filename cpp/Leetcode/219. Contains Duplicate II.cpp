//https://leetcode.com/problems/contains-duplicate-ii/
//LINK OF QUESTION 
//AND QUES NO AS HEADING

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        
        unordered_map<int,int>m;
        
       
        
      
        for(int i=0;i<n.size();i++)
        {
            
    
               if(m.count(n[i])!=0 and (i-m[n[i]]<=k))
               {
                   
                    return true;
                   
                }   
            
            
    
                      m[n[i]]=i; 
      
            //cout<<m[n[i]];
            
        }
        return false;
        
    }
};
