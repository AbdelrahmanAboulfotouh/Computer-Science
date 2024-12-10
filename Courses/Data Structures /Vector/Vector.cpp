#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;
class Vector{
private:
    int* arr = nullptr;
    int size = 0;
    int capacity = 0;
public:
    Vector(int size_){
        size = size_;
        size = (size < 0)? 1:size_;
        arr = new int[size];
        capacity=2*size_;
    }


    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
    int Size()
    {
        return size;
    }

    int get(int idx)
    {
        assert(0<=idx and idx <=size);
        return arr[idx];
    }
    int set (int idx, int val)
    {
        assert(0<=idx and idx <=size);
        arr[idx]  = val;
    }
    int get_front()
    {
        return arr[0];
    }
    int get_back(){
        return arr[size - 1];
    }
    void expand()
    {
        capacity*=2;
        int* temp =new int [capacity];
        for(int i{0};i<size;++i)
        {
            temp[i] = arr[i];
        }
        swap(arr,temp);
        delete[] temp;
    }
    void pus_back(int val)
    {
        if(size == capacity)
            expand();
        arr[size++] =val;
    }
    void insert(int val,int idx)
    {
        if(size == capacity)
            expand();
        assert(idx>=0 and idx<= capacity);
        for(int i = size-1;i>= idx;++i)
        {
            arr[i+1] = arr[i];
        }
        arr[idx] = val;
        ++size;

    }
    void right_rotate()
    {
        int last = arr[size-1];
        for(int i = size-2;i>=0;--i)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = last;
    }
    void left_rotate(){
        int first = arr[0];
        for(int i{0};i<size-1;++i)
        {
            arr[i] = arr[i+1];
        }
        arr[size-1] = first;
    }
    void right_rotate(int times)
    {
        times%=size;
        while (times --)
        {
            right_rotate();
        }
    }
    int pop(int idx)
    {
        assert(idx>=0 and idx<size);
        int del = arr[idx];
        for(int i{idx};i<size-1;++i)
        {
            arr[i] = arr[i+1];
        }
        size--;
        return del;

    }
    int find_transposition(int value)
    {
        int pos{-1};
        for(int i{0};i<size;++i)
            if(arr[i] == value)
            {
                pos = i;
                break;
            }
        if(pos >0)
            swap(arr[pos],arr[pos-1]);

        return pos;
    }

};
