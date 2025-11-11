#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class Stack{
    private:
        Node<T>* top;
    public:
        Stack (){
            top = nullptr;
        }
        bool is_empty(){
            return (top == nullptr);
        } 

        Node<T>* peek(){
            return top;
        }

        void push(T val){
            Node<T>* newNode = new Node<T>;
            newNode->data = val;
            newNode->next = top;
            top = newNode;
        }

        Node<T>* pop(){
            if (top == nullptr) return nullptr;
            Node<T>* temp = top;
            top = top->next;
            return temp;
        }

        bool valid_parentheses(string s){
            Stack<char> c;
            for (char i : s){
                if(i == '(' || i == '[' || i=='{'){
                    c.push(i);
                } else if (i == ')' || i == ']' || i=='}'){
                    if (c.is_empty()) return false;
                    Node<T>* top = c.peek();
                    if(
                    (top->data == '{' && i == '}') ||
                    (top->data == '[' && i == ']') ||
                    (top->data == '(' && i == ')'))
                    {
                        c.pop();
                    } else {
                        return false;
                    }
                }
            }
            return c.is_empty();
        }
};