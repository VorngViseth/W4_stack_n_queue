#include <iostream>

using namespace std;

template <typename Data>
struct Node {
    Data data;
    Node* next;
};

template <typename Data>
class Queue {
private:
    Node<Data> *front;
    Node<Data> *rear;
    int size;
public:
    Queue() {
        this->front=this->rear=nullptr;
        this->size = 0;
    }

    int getSize() {return this->size;}

    int getFront() {return front->data;}

    int getRear() {return rear->data;}

    void printQueue() {

        if(size == 0) {
            cout<< "queue is empty" << endl;
            return;
        }

        Node<Data> *current;
        current = front;

        while (current != nullptr) {
            cout << current->data;
            if(current->next != nullptr) cout<<" -> ";
            current = current->next;
        }

        cout<<endl;

    }

    void enqueue(int data) {
        Node<Data> *newNode = new Node<Data>{data, nullptr};

        if(size == 0) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++ ;

    }

    void dequeue() {
        Node<Data> *temp;
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