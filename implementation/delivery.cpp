#include <iostream>
#include <string>
#include <vector>
#include "../queue/queue.cpp"

using namespace std;

struct Order {
    int id;
    string item;
    string description;
    string location;
    string phone_number;
};

// this code is from AI since I get a lot of error That i dont understand and AI told me to add this block of code 
// From what i learned about this code It tells C++ how to print an Order object using cout or any other output stream
ostream& operator<<(ostream& os, const Order& order) {
    os << "[Order #" << order.id << "] "
       << order.item << " - " << order.description
       << " | Location: " << order.location
       << " | Phone: " << order.phone_number;
    return os;
}


void add_new_order(Queue<Order>& orders,int& order_id_counter){
    string item, description, location;
    string phone_num;

    cout<<"Enter item to be delivered: ";
    cin.ignore();
    getline(cin, item);
    cout<<"Enter description: ";
    getline(cin, description);
    cout<<"Enter location: ";
    getline(cin, location);
    cout<<"Enter customer's phone number: ";
    getline(cin, phone_num);
    Order newOrder;
    newOrder.id = order_id_counter++;
    newOrder.item = item;
    newOrder.description = description;
    newOrder.location = location;
    newOrder.phone_number = phone_num;


    orders.enqueue(newOrder);
    cout<<"Order #"<<newOrder.id<<" added to the queue.\n";
}
void view_order(Queue<Order>& orders){
    cout<<"\nPending Orders:\n";
    orders.printQueue();
}

void complete_order(Queue<Order>& orders,vector<Order>& completed_orders){
    if (!orders.isEmpty()) {
        Order completed = orders.dequeue();
        completed_orders.push_back(completed);
        cout<<"Order #" <<completed.id<<" has been dispatched.\n";
    } else {
        cout<<"No pending orders.\n";
    }
}

void view_completed(vector<Order>& completed_orders){
    cout<<"\nCompleted Orders:\n";
    for (const auto& order : completed_orders) {
        cout<<"Order #"<<order.id << ": "<<order.item<<" to "<<order.location<< "\n";
    }
}

void view_current_order(Queue<Order>& orders){
    cout<<orders.getFront();
}

int main() {
    Queue<Order> orders;
    vector<Order> completed_orders;
    int choice = 0;
    int order_id_counter = 1;

    while (choice != 6) {
        cout<<"\nWelcome to Delivery Queue System\n";
        cout<<"1. Add New Order\n";
        cout<<"2. View Pending Orders\n";
        cout<<"3. Complete Order\n";
        cout<<"4. View Completed Orders\n";
        cout<<"5. View current orders\n";
        cout<<"6. exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == 1) {
            add_new_order(orders,order_id_counter);
        } else if(choice == 2) {
            view_order(orders);
        } else if (choice == 3){
            complete_order(orders,completed_orders);
        } else if( choice == 4 ){
            view_completed(completed_orders);
        } else if ( choice == 5 ){
            try{
                view_current_order(orders);
            } catch (const runtime_error& e){
                cout<<"There's no order left."<<endl;
            }
        } else if ( choice == 6) {
            cout<<"exiting...";
            break;
        } else {
            cout<<"Invalid choice. Try again.\n";
        }
    }
    return 0;
}