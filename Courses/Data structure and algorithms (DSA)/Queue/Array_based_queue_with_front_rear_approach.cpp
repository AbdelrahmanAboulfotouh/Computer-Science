
#include <bits/stdc++.h>
using namespace std;
/*
 * Queue ADT
●
●
●
●
We need to design a data structure that follows FIFO
enqueue(value): Add in the end (rear) of the queue
dequeue(): Delete from the front of the queue
Useful functionalities:
○
●
isEmpty(), isFull(), clear(), frontQueue(), rearQueue()
Any implementation that satisfies this (FIFO) = Queue
 */
class Queue {
private:
    int size{ };
    int* arr{};
    int rear{ };
    int front{};

public:
    Queue(int size):size(size){
        arr = new int[size];
    }
    void enqueue(int value){
        assert(rear<size);
        arr[rear++] = value ;
    }
    int  dequeue(){
        assert(front <size);
        return arr[front++];
    }








};