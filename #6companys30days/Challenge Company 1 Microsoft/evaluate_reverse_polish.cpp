//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
class Solution {
    int calculate(int a,int b,string s){
        if(s=="+")return a+b;
        if(s=="-")return a-b;
        if(s=="*")return a*b;
        if(s=="/")return a/b;
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
      stack<int>st;
      for(auto it:tokens){
          if(it=="+" || it=="-" || it=="*" || it=="/"){
              int b=st.top();
              st.pop();
              int a=st.top();
              st.pop();
              st.push(calculate(a,b,it));
          }
          else{
              st.push(stoi(it));
          }
      }
      return st.top();  
    }
};