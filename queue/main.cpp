#include <iostream>
#include "queue.cpp"
using namespace std;

int main(){

    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(30);
    queue.enqueue(10);
    queue.enqueue(20);

    cout << queue.getFront() << endl;

    queue.printQueue();

    queue.dequeue();
    queue.printQueue();

    cout << queue.getFront() << endl;


}
