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

    Queue<char> charqueue;

    charqueue.enqueue('c');
    charqueue.enqueue('e');
    charqueue.enqueue('a');
    charqueue.enqueue('a');
    charqueue.enqueue('d');


    cout << charqueue.getFront() << endl;

    charqueue.printQueue();

    charqueue.dequeue();
    charqueue.printQueue();

    cout << charqueue.getFront() << endl;


}
