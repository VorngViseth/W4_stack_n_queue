#include <iostream>
#include <stack>
using namespace std;

 

bool isBalanced(string s){
    stack<char> st;
      int pos=1;
     
    for( char c:s){
    if(c=='(' || c=='{' || c=='['){
        st.push(c);

    }
     else if(c==')' || c=='}'  || c==']'){
         if(st.empty()){
          cout<<"error at pos "<<pos<<endl;
            return false;
        
         }
         char top = st.top();
         st.pop();
         if((c==')' && top!='(') ||(c=='}' && top!='{') ||(c==']' && top!='[')){
            cout<<"error at pos "<<pos<<endl;
            return false;
         }
    }
    pos++;
}
 return st.empty();
}

