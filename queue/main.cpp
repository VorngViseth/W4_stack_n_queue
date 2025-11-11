#include <iostream>
#include "queue.cpp"
using namespace std;

int main(){

    Queue queue;

    queue.enqueue(10);
    queue.enqueue(30);
    queue.enqueue(10);
    queue.enqueue(20);

    queue.printQueue();

    queue.dequeue();
    queue.printQueue();

}
