#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front;
    Node *rear;
    int size;
public:
    Queue() {
        this->front=this->rear=nullptr;
        this->size = 0;
    }

    int getSize() {return this->size;}

    char getFront() {return front->data;}

    char getRear() {return rear->data;}

    void printQueue() {

        if(size == 0) {
            cout<< "queue is empty" << endl;
            return;
        }

        Node *current;
        current = front;

        while (current != nullptr) {
            cout << current->data;
            if(current->next != nullptr) cout<<" -> ";
            current = current->next;
        }

        cout<<endl;

    }

    void enqueue(int data) {
        Node *newNode = new Node{data, nullptr};

        if(size == 0) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++ ;

    }

    void dequeue() {
        Node *temp;
        temp = front;

        if(size == 0) {
            cout << "queue is empty" << endl;
            return;
        }

        front = front->next;
        delete temp;
        size-- ;

        if(size == 0) front = rear = nullptr;

    }
};