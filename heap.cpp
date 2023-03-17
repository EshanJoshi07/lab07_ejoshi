// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size() - 1;
  while (i > 0 && vdata[(i - 1) / 2] > vdata[i]) {
    int temp = vdata[(i - 1) / 2];
    vdata[(i - 1) / 2] = vdata[i];
    vdata[i] = temp;
    i = (i - 1) / 2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.size() == 0) {
    return;
  }
  vdata[0] = vdata.back();
  vdata.pop_back();

  // Fix the heap property by comparing the new root to its children
  int i = 0;
  while ((i * 2) + 1 < vdata.size()) {
    // Find the index of the smallest child
    int min_child_index = (i * 2) + 1;
    if ((i * 2) + 2 < vdata.size() && vdata[(i * 2) + 2] < vdata[min_child_index]) {
      min_child_index = (i * 2) + 2;
    }

    // If the parent is larger than the smallest child, swap them
    if (vdata[i] > vdata[min_child_index]) {
      int temp = vdata[i];
      vdata[i] = vdata[min_child_index];
      vdata[min_child_index] = temp;

      // Update the index to the smallest child's index
      i = min_child_index;
    } 
    else {
      break;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.size() == 0) {
    return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.size() == 0;
}
