class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      long long MOD = 1000000007; 
      sort(horizontalCuts.begin(), horizontalCuts.end());
      sort(verticalCuts.begin(),verticalCuts.end());
      long long hDiff = (1LL)*horizontalCuts[0];
      long long i = 0;
      for(i=1; i<horizontalCuts.size(); i++)
      {
        if(horizontalCuts[i]-horizontalCuts[i-1] > hDiff)
          hDiff = 1LL*(horizontalCuts[i]-horizontalCuts[i-1]);
      }
      if(h-horizontalCuts[i-1] > hDiff)
        hDiff = 1LL*(h - horizontalCuts[i-1]);
      
      long long wDiff = 1LL*verticalCuts[0]; i=0;
      for(i=1; i<verticalCuts.size(); i++)
      {
        if(verticalCuts[i]-verticalCuts[i-1] > wDiff)
          wDiff = 1LL*(verticalCuts[i]-verticalCuts[i-1]);
      }
      if(w-verticalCuts[i-1] > wDiff)
        wDiff = 1LL*(w - verticalCuts[i-1]);
      
      int area = ((hDiff%MOD)*(wDiff%MOD))%MOD;
      return area;
    }
};