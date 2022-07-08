class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
      unordered_set<string> mailset;
      for(auto email : emails)
      {
        string newEmail = "";
        for(auto ch : email)
        {
          if(ch == '.')continue;
          if(ch == '@' || ch == '+')break;
          newEmail += ch;
        }
        newEmail += email.substr(email.find('@'));
        mailset.insert(newEmail);
      }
      return mailset.size();
    }
};