//https://leetcode.com/problems/license-key-formatting/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string ans,st;
        int k1=0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]!='-')
            {
                ans.push_back(toupper(s[i]));
                continue;
            }
              
               
        }
      for(int i=0;i<ans.length();i++)
      {
         
          if(++k1<=k)
          {
               st.push_back(ans[i]);
              
             
          }
      
           else if(k1>k)
          {
              st.push_back('-');
              k1=0;
               i--;
          }
      }
         reverse(st.begin(),st.end()); 
        
          
      
        
        return st;
        
    }
};
