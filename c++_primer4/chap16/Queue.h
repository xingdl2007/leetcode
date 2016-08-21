#ifndef __QUEUE_H__
#define __QUEUE_H__

// declaration that Queue is a template needed for friend declaration in QueueItem
template <class Type> class Queue;
// function template declaration must precede friend declaration in QueueItem
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class Type> class QueueItem {
    friend class Queue<Type>;
    // needs access to item and next
    friend std::ostream&     // defined on page 659
    operator<< <Type> (std::ostream&, const Queue<Type>&);
    
    // private class: no public section
    QueueItem(const Type &t): item(t), next(0) { }
    Type item;           // value stored in this element
    QueueItem *next;     // pointer to next element in the Queue
};

template <class Type> class Queue {
    // needs access to head
    friend std::ostream& // defined on page 659
    operator<< <Type> (std::ostream&, const Queue<Type>&);

public:
    // empty Queue
    Queue(): head(0), tail(0) { }
    // construct a Queue from a pair of iterators on some sequence
    template <class It>
    Queue(It beg, It end):
        head(0), tail(0) { copy_elems(beg, end); }
    // copy control to manage pointers to QueueItems in the Queue
    Queue(const Queue &Q): head(0), tail(0)
                                { copy_elems(Q); }
    Queue& operator=(const Queue&); // left as exercise for the reader
    ~Queue() { destroy(); }
    // replace current Queue by contents delimited by a pair of iterators
    template <class Iter> void assign(Iter, Iter);
    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()             { return head->item; }
    const Type &front() const { return head->item; }
    void push(const Type &);// defined on page 652
    void pop();             // defined on page 651
    bool empty() const {           // true if no elements in the Queue
        return head == 0;
}
private:
    QueueItem<Type> *head;   // pointer to first element in Queue
    QueueItem<Type> *tail;   // pointer to last element in Queue
// utility functions used by copy constructor, assignment, and destructor
void destroy();                // defined on page 651
void copy_elems(const Queue&); // defined on page 652
// version of copy to be used by assign to copy elements from iterator range
// defined on page 662
template <class Iter> void copy_elems(Iter, Iter);
};

// Inclusion Compilation Model: include member function definitions as well
#include "Queue.cc"

#endif