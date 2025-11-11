#include <iostream>
#include <stack>
#include "stack.cpp"
using namespace std;

int main(){

string s="if[ao]";

 if(isBalanced(s)){
    cout<<"OK";
 }
 else {
    cout<<"Not balance";
 }

    return 0;
}
