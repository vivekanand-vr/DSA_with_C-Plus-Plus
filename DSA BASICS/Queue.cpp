#include <bits/stdc++.h>
using namespace std;


//Queue implementation using array
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
      arr[rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{   
        if(rear==front)
            return -1;
            
        return arr[front++];
}


// A structure to represent a queue 
class Queue 
{ 
    public:
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 

// function to create a queue of a given capacity. 
// It initializes the size of the queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
    Queue* queue = new Queue();
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; // This is important, see the enqueue 
    queue->array = new int[(queue->capacity * sizeof(int))]; 
    return queue; 
} 

// Queue is full when size 
// becomes equal to the capacity 
int isFull(Queue* queue) 
{ return (queue->size == queue->capacity); } 

// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ return (queue->size == 0); } 

// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    cout << item << " enqueued to queue\n"; 
} 

// Function to remove an item from the queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 

// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 









//Queue implementation using linked list
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; 

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode* newNode=new QueueNode(x);
    if(front==NULL)
    {
        front = newNode;
        rear = front;
    }
    
    else
    {
        rear -> next = newNode;
        rear = rear -> next;
    }  
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL)
        return -1;
    
    int a = front -> data;
    QueueNode* temp = front;
    front = front -> next;
    
    delete temp;
    return a;   
}