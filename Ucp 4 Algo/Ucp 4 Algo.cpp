#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;
};

// Queue class
class Queue
{
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Function to insert an element into the queue
    void insert()
    {
        int value;
        cout << "Enter value to insert: ";
        cin >> value;

        Node* newNode = new Node();  // Step 1
        newNode->data = value;       // Step 2
        newNode->next = NULL;        // Step 3

        if (front == NULL)           // Step 4: If the queue is empty
        {
            front = newNode;         // Step 4a
            rear = newNode;          // Step 4b
        }
        else
        {
            rear->next = newNode;    // Step 5
            rear = newNode;          // Step 6
        }
        cout << "Inserted " << value << " into the queue\n";
    }

    // Function to delete an element from the queue
    void deleteQueue()
    {
        if (front == NULL)           // Step 1: If the queue is empty
        {
            cout << "Queue empty\n"; // Step 1a
            return;
        }

        Node* current = front;       // Step 2
        front = front->next;         // Step 3
        delete current;              // Step 4

        if (front == NULL)           // If the queue becomes empty after deletion
        {
            rear = NULL;
        }
        cout << "Deleted element from the queue\n";
    }

    // Function to display all elements of the queue
    void display()
    {
        if (isEmpty()) // step 1
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deleteQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again\n";
        }
    } while (choice != 4);

    return 0;
}
