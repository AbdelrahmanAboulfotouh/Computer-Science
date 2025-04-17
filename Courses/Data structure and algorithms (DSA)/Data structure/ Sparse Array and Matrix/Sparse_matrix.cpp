#include <iostream>
#include "Array and Matrix_1D.cpp"
using namespace std;
struct MatrixNode{
    ArrayLinkedList Array ;
    int idx{ };
    MatrixNode* next{ };
    MatrixNode* pre{ };
    MatrixNode(ArrayLinkedList Array,int idx):Array(Array),idx(idx){};
};
class SparseMatrix{
private:
    int len{ };
    int wid{ };
    int act_len{-1};
    MatrixNode* Head{ };
    void link(MatrixNode* first, MatrixNode* second)
    {
        if(first)
            first->next = second;
        if(second)
            second->pre = first;
    }
public:
    SparseMatrix(int len, int wid): len(len),wid(wid){};
    void set_value(int value,int i, int j)
    {
        bool Found = false;
        //if there is already a node exists
        for (auto cur = Head; cur;cur = cur->next)
        {
            if(cur->idx == i)
            {
                 Found = true;
                cur->Array.set_value(value,j);
                break;
            }

        }
        if(!Found)
        {
            ArrayLinkedList List(wid);
            auto newNode = new MatrixNode(List,i);
            newNode->Array.set_value(value,j);
            if(!Head) {
                Head = newNode;
                return;
            }
            auto tail = Head;
                           while (tail->next)
                tail = tail->next;
            auto tmp = tail->next;
            link(tail,newNode);
            link(newNode,tmp);
        }

    }
    void print_Matrix() {
        auto cur = Head ;
        for(int c{0};  c<len ;++c)
        {
            if(cur and cur->idx == c) {
                cur->Array.print();
                cur = cur->next;
            }
            else
            {
                int x = wid;
                while (x--)
                    cout<<0<<" ";
                cout<<endl;
            }
        }
        cout<<endl;

    }
    void print_non_zero(){
        for(auto cur = Head; cur; cur = cur->next)
        {
            cur->Array.print_array_nonzero();
        }
    }
    void add(SparseMatrix List2)
    {
        for(auto cur = Head, cur2 = List2.Head ; cur ; cur2 = cur2->next ,cur = cur->next)
        {
            cur->Array.add(cur2->Array);
        }
    }
};

void test_sparse() {
    SparseMatrix mat(10, 10);
    mat.set_value(5, 3, 5);
    mat.set_value(7, 3, 7);
   mat.set_value(2, 3, 2);
    mat.set_value(0, 3, 2);
   /* mat.set_value(6, 5, 6);
    mat.set_value(4, 5, 4);
    mat.set_value(3, 7, 3);
    mat.set_value(1, 7, 1);
    //mat.set_value(1, 70, 1);*/
    mat.print_Matrix();
  //  mat.print_non_zero();

    SparseMatrix mat2(10, 10);
    mat2.set_value(5, 1, 9);
    mat2.set_value(6, 3, 8);
    mat2.set_value(9, 9, 9);
    //mat.add(mat2);
    //mat.print_matrix_nonzero();
}

int main()
{
    test_sparse();
    return 0;
}