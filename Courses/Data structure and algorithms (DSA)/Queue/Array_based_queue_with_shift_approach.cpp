
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

public:
    Queue(int size):size(size){
        arr[size];
    }
    void enqueue(int value){
        arr[rear++] = value ;
    }
    int  dequeue(){
       int first = arr[0];
       for(int i{0} ; i<size-1; ++i)
           arr[i] = arr[i+1];
        return first;
    }








};