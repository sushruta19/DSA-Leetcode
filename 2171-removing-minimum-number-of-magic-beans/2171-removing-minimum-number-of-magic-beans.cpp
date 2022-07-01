class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
      int n = beans.size();
      sort(beans.begin(), beans.end(), [](int a, int b) {
        return a>b;
      });
      long long totalBeans = 0, minBeansRemoved = LLONG_MAX;
      for(auto bean:beans)
        totalBeans+=(1LL)*bean;
      
      for(int i=0; i<n; i++)
      {
        long long beansLeft = (1LL*beans[i])*(1LL*(i+1));
        long long beansRemoved = totalBeans - beansLeft;
        minBeansRemoved = min(minBeansRemoved,beansRemoved);
      }
      return minBeansRemoved;
    }
};