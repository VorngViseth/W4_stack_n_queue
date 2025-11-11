#include "stack.cpp"
using namespace std;

int main(){
    Stack<char> stack;
    string n = "sjdklfjajsdf()()()()()";
    cout<<stack.valid_parentheses(n);
};
