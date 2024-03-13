#include <iostream>
#include"bits/stdc++.h"

using namespace std;

//////////////////////// vector

class Vector{
private:
    int* arr=nullptr;
    int size=0;
    int capacity=0;
public:
    Vector(int Size):
            size(Size){
        if (Size<=0){size=1;}
        capacity=size+1000;
        arr =new int[capacity]{ };
    }
    int get(int idx)
    {
        assert(idx>=0 && idx<size);
        return arr[idx];
    }

    void set(int idx,int val)
    {
        assert(idx>=0 && idx <size);
        arr[idx]=val;
    }
    int get_size()
    {
        return size;
    }
    void print()
    {
        for( int i =0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    int find(int val)
    {
        for (int i = 0; i < size; ++i) {
            if (arr[i]==val)
            {
                return 1;
            }
        }
        return -1;
    }
    ~ Vector()
    {
        delete[] arr;
        arr= nullptr;
    }
    void push_back(int val)
    {
        if (size==capacity)
        {
            change_capacity();

        }
        arr[size++]=val;
    }
    void change_capacity()
    {
        capacity*=2;
        int* arr2=new int[capacity] { };
        for (int i = 0; i < size; ++i) {
            arr2[i]=arr[i];
        }
        swap(arr,arr2);
        delete[]arr2;
    }
    void insert(int val,int idx)
    {
        if (size==capacity)
        {
            change_capacity();
        }
        assert(idx>=0 && idx<size);

        for (int i = size-1; i >= idx; --i)
        {
            arr[i+1]=arr[i];
        }
        arr[idx]=val;
        size++;   // to change size after adding an element
    }
    void right_rotate()
    {
        int temp=arr[size-1];
        for (int i = size-2; i >= 0 ; --i)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=temp;
    }
    void left_rotate()
    {
        int temp=arr[0];
        for (int i = 1; i < size; ++i) {
            arr[i-1]=arr[i];
        }
        arr[size-1]=temp;
    }
    void right_rotate(int times)  // rotation with steps
    {
        int time=times%size;
        while(time--)
        {
            int temp=arr[size-1];
            for (int i = size - 2; i >= 0; --i) {
                arr[i + 1] = arr[i];
            }
            arr[0] = temp;
        }
    }
    int pop(int idx)
    {
        assert(idx>=0 && idx<size);
        int ans = arr[idx];
        reduce_size(idx);
        return ans;
    }
    void reduce_size(int idx)
    {
        int*arr2 = new int[capacity];
        bool s=true;
        for (int i = 0; i < size; ++i)
        {
            if(i==idx)
            {
                s= false;
                continue;
            }
            if (s)
            {
                arr2[i]=arr[i];
            }
            else
            {
                arr2[i-1]=arr[i];
            }
        }
        size--;
        swap(arr,arr2);
        delete[]arr2;
    }
    int find_transposition(int val)
    {
//        assert(idx>=0 && idx<size);
        for (int i = 0; i < size; ++i) {
            if (val==i)
            {
                if (i!=0)
                {
                    swap(arr[i-1],arr[i]);
                    return i-1;
                }
            }
        }
        return-1;
    }
};

//-------------------------------

///////////////////////// Nodes
struct Node {
    int data { };
    Node* next { };
    Node(int data) : data(data) {}
    ~Node() {
        cout << "Destroy value: " << data <<" at address "<< this<< "\n";
    }
};


void print(Node* head)
{
    if (head== nullptr)
    {
        cout<<"\n";
        return;
    }
    print(head->next);
    cout<<head->data<<" ";
}


Node* find(int val,Node*head)
{
    while(head!= nullptr)
    {
        if (head->data==val)
        {
            return head;
        }
        head=head->next;
    }
    return nullptr;
}

//-------------------------------

///////////////////////// SLL

class Linked_list
{
private:
    Node* head {};
    Node* tail {};
    int length =0;
    vector<Node*> debug_data;	// add/remove nodes you use

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    } // pushes the given node into vector

    void debug_remove_node(Node* node) {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }  // checks if vector is empty to delete nodes

public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    Linked_list() {
    }
    Linked_list(const Linked_list&) = delete;
    Linked_list &operator=(const Linked_list &another) = delete;

    void debug_print_address() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }  // prints address and content

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

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }  // prints data of nodes and if tail or head

    void debug_print_list(string msg = "") {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int) debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n"<<flush;
    }  // prints the vector of nodes

    string debug_to_string() {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node* cur = head; cur; cur = cur->next) {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }  //  converts nodes data to string

    void debug_verify_data_integrity() {
        if (length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
        } else {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++)
            assert(len < 10000);	// Consider infinite cycle?
        assert(length == len);
        assert(length == (int)debug_data.size());
    }

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node* node) {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node* node) {
        debug_add_node(node);
        ++length;
    }

    void print()
    {
        Node* temp=head;
        while(temp!= nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }

    void insert_end(int val)
    {
        Node* temp=new Node(val);
        if (!head)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
            tail->next= nullptr;
        }
//        length ++;
        add_node(temp);
    }  // inserts or adds an element to the end of the list

    Node* get_nth(int n)
    {
        Node*cur=head;
//        int temp=length;
        for (int i = 1; i <= length; ++i) {
            if (i==n)
            {
                return cur;
            }
            cur=cur->next;
        }
    }  // gets the desired indexed element

    Node* get_nth_back(int n)
    {
        Node*cur=head;
//        int temp=length;
        for (int i = 0; i < length; ++i) {
            if (i==length-n)
            {
                return cur;
            }
            cur=cur->next;
        }
        return nullptr;
    }  // gets the desired indexed element starting from the back

    int find(int val)
    {
        int count=0;
        for(Node* cur=head;cur;cur=cur->next)
        {
            if (cur->data==val)
            {
                return count;
            }
            count++;
        }
        return -1;
    }  // searches for an element in the list

    void improved_search(int val)
    {
        int temp;
        Node* before;
        if (head->data != val)
        {
            before=head;
        }
        for(Node*cur=head;cur;cur=cur->next)
        {
            if (cur->data==val)
            {
                if (cur==head)
                {
                    return;
                }
                temp=before->data;
                before->data=cur->data;
                cur->data=temp;
                return;
            }
            before=cur;
        }
    }  // for everytime an element is searched for it is moved towards the head of the list

    void insert_front(int val)
    {
        Node* temp=new Node(val);
        add_node(temp);
        if (!head)
        {
            head=tail=temp;
        }
        else
        {
            for (int i = length-2; i >= 0; --i)
            {
                debug_data[i+1]=debug_data[i];
            }
            debug_data[0]=temp;
            temp->next=head;
            head=temp;
        }

    }  // inserts an element to the front of the list

    void delete_front()
    {
        assert(length);
        Node* before=head->next;
//        Node* cur=head;
        delete_node(head);
        head=before;
    }  // deletes from the front

    void delete_back()
    {
        assert(length);
        if (length==1)
        {
            delete_front();
        }
        else
        {
            delete_node(tail);
            tail= get_nth_back(1);
            tail->next= nullptr;
        }
    }  // deletes the last element

    void delete_nth(int n)
    {
        assert(n<=length && n>0);
        if (n==1)
        {
            delete_front();
        }
        else if (n==length)
        {
            delete_back();
        }
        else
        {
            Node* temp= get_nth(n-1);
            Node* cur=temp->next;
            temp->next=temp->next->next;
            delete_node(cur);
        }
    }  // deletes the indexed element

    void delete_with_key(int val)
    {
        delete_nth(find(val)+1);
    }  // deletes the node with the given key/data

    void swap_pairs()
    {
        assert(length >1);
        for (Node* cur=head; cur ; cur=cur->next->next) {
            Node*temp=cur->next;
            if (!temp)
            {
                break;
            }
            int New=temp->data;
            temp->data=cur->data;
            cur->data=New;
            if (cur->next==tail)
            {
                break;
            }
        }
    }  // swaps list pairs

    void reverse()
    {
        if (head == nullptr || head->next == nullptr) {
            return; // Nothing to reverse if the list is empty or has only one node
        }

        Node *prev = nullptr;
        Node *current = head;Node *ord = head;
        Node *nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next; // Store the next node

            // Reverse the link
            current->next = prev;

            // Move pointers one position ahead
            prev = current;
            current = nextNode;

        }

        // Finally, update the head to point to the new first node (which was originally the last node)
        head = prev;
        tail=ord;  // to maintain the lists order;
    }  // reverses the node

    bool is_same_length(const Linked_list&other)
    {
        assert(length==other.length);
        for (int i = 0; i < length; ++i) {
            if (debug_data[i]->data!=other.debug_data[i]->data)
            {
                return false;
            }
        }
        return true;
    }  // compares 2 obj as if they are the same considering length parameter is implemented

    bool is_same(const Linked_list&other)
    {
        Node*n_cur=other.head;
        for (Node* cur=head;cur;cur=cur->next)
        {
            if (n_cur->data!=cur->data)
            {
                return false;
            }
            n_cur=n_cur->next;
        }
        if(n_cur)   // to check for the tail's nullptr
        {
            return false;
        }
        return true;
    }  // compares 3 obj considering length isn't available

    void delete_even_pos()
    {
        assert(length>0);
        int temp=length/2;
        for (int i = 2; temp>0; i++,temp--) {
            delete_nth(i);
        }
    }  // deletes even position nodes

    void insert_after(Node*node,int val)
    {
        Node*temp=new Node(val);
        add_node(temp);
        temp->next=node->next;
        node->next=temp;
    }  // inserts after the given node

    void insert_sorted(int val){
        if (length==0 || head-> data>=val)
        {
            insert_front(val);
        }
        else if (tail->data<=val)
        {
            insert_end(val);
        }
        else
        {
            Node*bef= nullptr;
            for (Node*cur=head;cur;cur=cur->next)
            {
                if (cur->data>=val)
                {
                    insert_after(bef,val);
                    break;
                }
                bef=cur;
            }
        }
    }  // inserts elements in a sorted way

    void swap_head_tail(){
        assert(length);
        Node* prev= nullptr;
        for (Node*cur=head;cur;cur=cur->next) {
            if (cur->next->next== nullptr)
            {
                prev=cur;
                break;
            }
        }
//        Node*temp=head->next;
//        head->next= nullptr;
//        tail->next=temp;
//        prev->next=head;
        Node*temp_h=head;
//        Node*temp_t=tail;
        int new_val=tail->data;
        head=tail;
        head->data=temp_h->data;
        prev->next=head;
        tail=temp_h;
        tail->data=new_val;
//        tail->next=temp;
    }

    ~Linked_list()
    {
        while(head!= nullptr)
        {
            Node* temp=head->next;
            delete_node(head);
            head=temp;
        }
    }  // destroys the pointers

};

class short_SLL{
private:
    Node* head { };
public:
    short_SLL(){};
    short_SLL(const short_SLL&)=delete;
    short_SLL&operator=(const short_SLL&another)=delete;

    void print()
    {
        for(Node* cur=head;cur;cur=cur->next)
        {
            cout<<cur->data<<" ";
        }
        cout<<"\n";
    }
    void add_element_n(int val)
    {
        Node* temp=new Node (val);
        if (!head)
        {
            head=temp;
            head->next= nullptr;
        }
        else
        {
            Node *ser = head;
            while (ser->next)
            {
                ser=ser->next;
            }
            ser->next=temp;
            ser->next->next= nullptr;
        }
    }  // O(n) implementation
    void add_element_1(int val)
    {
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
    }  // O(1) implementation

    Node* get_tail()
    {
        Node*temp=head;
        while(!temp)
        {
            temp=temp->next;
        }
        return temp;
    }

};  // linked list with neither tail nor length parameter

void test1() {
    cout << "\n\ntest1\n";
    Linked_list list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_front(4);
    list.delete_back();
    list.print();

    list.debug_verify_data_integrity();
    string expected = "4 1 2";
    string result = list.debug_to_string();
    if (expected != result) {
        cout << "no match:\nExpected: " <<
             expected << "\nResult  : " << result << "\n";
//        assert(false);
    }
    list.debug_print_list("********");
}

void test2() {
    cout << "\n\ntest2\n";
    Linked_list list;Linked_list list2;
    string ans;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.delete_back();list.delete_back();list.delete_back();

//    if (list.is_same(list2)) ans="true";
//    else ans="false";
    // some actions
//    list.print();
    list.debug_verify_data_integrity();
    string expected = "1";
    string result = list.debug_to_string();
    if (expected != result) {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
//        assert(false);
    }
    list.debug_print_list("********");
}
void test3() {
    cout << "\n\ntest3\n";
    Linked_list list;Linked_list list2;
    string ans;

    list.insert_end(1);list.insert_end(2);list.insert_end(3);list.insert_end(4);
    list.swap_head_tail();
    list.print();

//    if (list.is_same(list2)) ans="true";
//    else ans="false";
    // some actions
//    list.print();

    string expected = "4 2 3 1";
    string result = list.debug_to_string();
    if (expected != result) {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
//        assert(false);
    }
    list.debug_print_list("********");
}

void test4(int a)
{
    string s;
    cin>>s;
    string ans="";int count=0;int lim=0;
    unordered_set<char>st;
    for(auto it : s)
    {
        st.insert(it);
    }
    for(auto it : st)
    {
        ans+=it;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]==s[i+1]&&count<=0)
        {
            lim++;
        }
        else
        {
            count++;
            if (s[i]==ans[0])
            {
                cout<<i+1-lim;
                break;
            }
        }
    }
}


int main() {

//   test1();
//   test2();
//    test3();
    int a;
    cin>>a;

    test4(a);
    // must see it, otherwise RTE
//    cout << "\n\nNO RTE\n";

}
/*

public:





	////////////////////////////////////////////////////////////

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}


	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	}

	////////////////////////////////////////////////////////////
};



int main() {

	return 0;
}

*/