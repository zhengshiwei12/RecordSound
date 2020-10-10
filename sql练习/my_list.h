template<typename T>
class node{
public:
    T value;
    node* next;
    node():next(nullptr){}
    node(T val,node* p=nullptr):value(val),next(p){}
};

template<typename T>
class my_list{
private:
    node<T>* head;
    node<T>* tail;
    int size;

private:
    class list_iterator{
    private:
        node<T>* ptr;
    public:
        list_iterator(node<T>* p=nullptr):ptr(p){}
        T& operator*()const{
            return ptr->value;
        }
        node<T>* operator->()const{
            return ptr;
        }
        list_iterator& operator++(int){
            node<T>*tmp=ptr;
            ++(*this);
            return list_iterator(tmp);
        }
        bool operator==(const list_iterator &t) const {
            return t.ptr == this->ptr;
        }

        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    }
public:
    typedef list_iterator iterator;
    my_list(){
        head=nullptr;
        tail=nullptr;
        size=0;
    }
    void push_back(const T& value)
    {
        if(head)
        {
            head=new node<T>(value);
            tail=head;
        }else{
            tail->next=new node<T>(value);
            tail=tail->next;
        }
        size++;
    }
public:
    iterator begin()const{
        return head;
    }
    iterator end()const{
        return tail->next;
    }
};