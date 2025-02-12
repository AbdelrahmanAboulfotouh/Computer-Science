
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data{};
    Node* next{};
    //Node(int data) : data(data){};
    Node(int data)
    {
        this->data =data;
    }

};

class Linkedlist{
private:
    Node* Head{};
    Node* tail{};
    int lenght {};
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<Node*> debug_data;	// add/remove nodes you use

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node) {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    Linkedlist() {
    }
    Linkedlist(const Linkedlist&) = delete;
    Linkedlist &operator=(const Linkedlist &another) = delete;

    void debug_print_address() {
        for (Node* cur = Head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_print_node(Node* node, bool is_seperate = false) {
        if (is_seperate)
            cout << "Sep: ";
        if (node == nullptr) {
            cout << "nullptr\n";
            return;
        }
        cout << node->data << " ";
        if (node->next == nullptr)
            cout << "X ";
        else
            cout << node->next->data << " ";

        if (node == Head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }
    void debug_print_list(string msg = "") {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int) debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n"<<flush;
    }

    string debug_to_string() {
        if (lenght == 0)
            return "";
        ostringstream oss;
        for (Node* cur = Head; cur; cur = cur->next) {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }

    void debug_verify_data_integrity() {
        if (lenght == 0) {
            assert(Head == nullptr);
            assert(tail == nullptr);
        } else {
            assert(Head != nullptr);
            assert(tail != nullptr);
            if (lenght == 1)
                assert(Head == tail);
            else
                assert(Head != tail);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = Head; cur; cur = cur->next, len++)
            assert(len < 10000);	// Consider infinite cycle?
        assert(lenght == len);
        assert(lenght == (int)debug_data.size());
    }

    ////////////////////////////////////////////////////////////Start///////////////////////////////////////////////////

    void print(){
    cout<<Head<<"  "<<tail<<endl;
        for(Node* current = Head; current ; current = current->next )
        {
            cout<<current->data<<" ";
        }
        cout<<endl;
    }
    void insert_back(int value)
    {
        Node* newnode = new Node(value);
        if(Head == nullptr)
        {
            Head = tail = newnode;
            debug_add_node(newnode);
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            debug_add_node(newnode);
        }
        ++lenght;

    }
    //time o(n), space o(1)
    Node* get_nth(int n)
    {
        int count{};
        for(Node* current = Head ; current ; current = current->next,++count)
        {
            if(count == n)
                return current;
        }
        return nullptr;
    }

    int search(int value)
    {
        int index{};
        for(Node* current = Head ; current ; current = current->next,++index)
        {
            if(current->data == value)
                return index;
        }
        return -1;
    }
    int search_improved(int value)
    {
        int index{};
        Node* pre{};
        for(Node* current = Head ; current ; pre = current,current = current->next,++index)
        {
            if(current->data == value)
            {
                if(pre)
                {
                    swap(current->data,pre->data);
                    return index-1;
                }
                else
                    return index;
            }
        }
        return -1;
    }

    //#1 time O(N), space o(1)
    ~Linkedlist()
    {
        while (Head)
        {
            Node* current =Head;
            Head = Head->next;
            delete current;
        }
    }

    //#2(easy) time O(1), space O(1)
    void inser_front( int value)
    {
        Node* newnode = new Node(value);
        newnode->next = Head;
        Head = newnode;
        ++lenght;
        if(lenght == 1)
            tail =Head;
    }

    //#3(easy) time o(1) , space o(1)
    void delete_front()
    {
        if(!Head)
            return;
        if(lenght > 1)
        {
            Node* current = Head;
            Head = Head->next;
            delete current;
        }
        else
        {
            delete Head;
            delete tail;
            Head = nullptr;
            tail = nullptr;
        }
        --lenght;
    }

    //#4(easy) time o(n), space o(1)
    Node* get_nth_back(int idx)
    {
        assert(idx <= lenght and idx>=1);
        return get_nth(lenght - idx +1);

    }

    //#5(easy) time o(n) space o(1)
    bool is_same(const Linkedlist &other)
    {
        if(lenght != other.lenght)
            return false;
        Node* curr = Head;
        for(Node* cur = other.Head; cur and curr ;cur = cur->next,curr =curr->next)
        {
            if(cur->data != curr->data)
                return false;
        }
        return true;
    }

    //#5 (easy) time o(n) space o(1)
    bool is_same_with_no_lenght(const Linkedlist &other)
    {

        Node* curr = Head;
        for(Node* cur = other.Head; cur and curr ;cur = cur->next,curr =curr->next)
        {
            if((cur->next == nullptr and curr->next != nullptr) or (curr->next == nullptr and cur->next != nullptr))
                return false;
            if(cur->data != curr->data)
                return false;
        }
        return true;
    }
    void delet_node(Node* node)
    {
        debug_remove_node(node);
        delete node;
        --lenght;
    }
    void delete_first()
    {
        if(Head)
        {
            Node* cur = Head;
            Head = Head->next;
            delet_node(cur);
        }
        if(Head == nullptr)
            tail = nullptr;
        debug_verify_data_integrity();
    }
    void delete_last()
    {
        if(lenght<=1)
            delete_first();
        Node* pre = get_nth(lenght - 1);
        debug_remove_node(tail);

        delet_node(tail);
        tail = pre;
        tail = nullptr;
        debug_verify_data_integrity();
    }
    void delete_nth(int idx)
    {
        assert(idx >=1 and idx <= lenght);
        if(lenght <= 1)
            delete_first();
        Node* pre = get_nth(idx - 1);
        Node* cur = pre->next;
        pre->next = cur->next;
        if(cur->next == nullptr)
            tail = pre;

        delet_node(cur);
        // debug_remove_node(cur);

        debug_verify_data_integrity();
    }

    // 1# HW2 easy
    void delete_node_with_key(int value)
    {
        int idx{0};
        bool f = false;
        for(Node* cur = Head; cur ; cur=cur->next)
        {
            if (cur->data == value)
            {
                f = true;
                break;
            }
            ++idx;
        }
        if(f)
        {
            if(idx < 1)
                delete_first();
            else
                delete_nth(idx);

        }

    }

    //Problem #2: Swap each pair vales HW2 easy
    void swap_pairs()
    {
        if(lenght <=1)
            return;
        for( Node* cur  = Head ; cur and cur->next ; cur = cur->next->next)
            swap(cur->data,cur->next->data);

    }
    //Problem #3: Reverse list nodes Hw 2
    Node* Reverse_list(Node* Head ) {
        Node *cur = Head->next;
        Node *pre = Head;
        for (Node *copy = cur; copy; copy = copy->next)
        {
            cur->next =pre;
            pre = cur ;
            cur = copy;
        }

        Head->next = nullptr;
        tail = Head;
        Head = cur ;
        return Head;
    }
    void delete_even_positions()
    {
        int c{1};
        Node* pre = Head;
        Node* cur = Head;
        while(cur) {
            if (c % 2 == 0)
            {
                Node *tmp = cur;
                if (cur->next == nullptr)
                {
                    pre->next = nullptr;
                    delete tmp;
                    break;
                } else
                {
                    pre->next = cur->next;
                    cur =cur->next;
                    delete tmp;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
            ++c;
        }

    }
    void insert_sorted(int value)
    {
        if(lenght < 1)
            insert_back(value);
        else
        {
            if(get_nth(lenght-1)->data <= value)
                insert_back(value);
            else
            {
                insert_back(value);
                swap(get_nth(lenght-1)->data, get_nth(lenght-2)->data);
            }
        }
    }
    void swap_head_by_tail()
    {
        if(lenght < 2)
            return;
        if(lenght < 3)
        {
           tail->next =Head;
           Head  = tail ;
           tail = Head->next;
           tail->next = nullptr;
        }
        else
        {
            auto pre = Head;
            for(; pre->next->next ; pre = pre->next);
            pre->next = Head;
            tail->next = Head->next ;
            Head->next = nullptr;
            swap(Head,tail);

        }
    }
};
//#6 (easy)  LinkedList with only a Head pointer
class LinkedList{
private:
    Node* Head;
public:




    // time O(n) space o(1)
    void print(){
        for(Node* cur = Head;cur; cur = cur->next)
        {
            cout<<cur->data;
        }
    }
//time o(1) space o(1)
    void add_element(int value)
    {
        Node* newnode = new Node(value);
        newnode->next = Head;
        Head = newnode;
    }
    Node* get_tail()
    {
        if(!Head)
            return nullptr;
        for(Node* cur =Head; cur ; cur = cur->next)
            if(cur->next == nullptr)
                return cur;
    }


};
int main()
{
    Linkedlist obj ;
    obj.insert_back(1);
    obj.insert_back(2);
    obj.insert_back(3);
    obj.print();
   obj.swap_head_by_tail();
   obj.print();
    return 0;
}
