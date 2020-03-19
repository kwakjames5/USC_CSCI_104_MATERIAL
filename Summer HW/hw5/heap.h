#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
 public:
  /// Constructs an m-ary heap for any m >= 2
  Heap(int m, PComparator c = PComparator());

  /// Destructor as needed
  ~Heap();

  /// Adds an item
  void push(const T& item);

  /// returns the element at the top of the heap 
  ///  max (if max-heap) or min (if min-heap)
  T const & top() const;

  /// Removes the top element
  void pop();

  /// returns true if the heap is empty
  bool empty() const;

 private:
  /// Add whatever helper functions and data members you need below

  // bring over old heapify from hsort
  // and update it
  void heapifyUpdated(int node);

  // degree
  int m;

  // comparator
  PComparator comp;

  // vector to store
  std::vector<T> store;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  // sets the degree and comparator
  this->m = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  // when store is empty, just push
  // in an item
  if(store.empty())
  {
    store.push_back(item);
    return;
  }
  else
  {
    // push in the item first
    store.push_back(item);

    // update all the positions for the next
    // time push is called
    int currentPos = store.size() - 1;
    while(comp(item, store[(currentPos - 1) / m]))
    {
      T temp = item;
      store[currentPos] = store[(currentPos - 1) / m];
      store[(currentPos - 1) / m] = temp;
      currentPos = (currentPos - 1) / m;
    }
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::logic_error("can't top an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return store[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::logic_error("can't pop an empty heap");
  }
  // re assign the nodes then pop back
  store[0] = store[store.size() - 1];
  store.pop_back();

  // re-heapify the updated heap
  heapifyUpdated(0);
}

// updated heapify function from hsort
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUpdated(int node)
{
  int start = node * m + 1;

  if((unsigned) start >= store.size())
  {
    return;
  }
  else
  {
    T min = store[start];
    int temp = start;
    int index = start;
    
    while(index <= (node * m + m) && (unsigned) index < store.size())
    {
      if(comp(store[index], min))
      {
        min = store[index];
        temp = index;
      }
      index++;
    }
    if(comp(min, store[node]))
    {
      T temp1 = store[node];
      store[node] = min;
      store[temp] = temp1;
      heapifyUpdated(temp);
    }
    else
    {
      return;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(store.empty()){
    return true;
  }
  return false;
}

#endif

