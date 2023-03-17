// heap.cpp
// Diba Mirza

// #include "heap.h"
// #include <iostream>
// using std::cout;

// // Pushes a value into the heap, then ensures
// // the heap is correctly arranged
// void Heap::push(int value){

// }

// // Pops the minimum value off the heap
// // (but does not return it), then ensures
// // the heap is correctly arranged
// void Heap::pop(){

// }

// // Returns the minimum element in the heap
// int Heap::top(){
//   return 0;
// }

// // Returns true if the heap is empty, false otherwise
// bool Heap::empty(){
//   return true;
// }
    
#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  // Add the new value to the end of the heap
  vdata.push_back(value);

  // Get the index of the new value
  int index = vdata.size() - 1;

  // Fix the heap property by comparing the new value to its parent
  while (index > 0 && vdata[(index - 1) / 2] > vdata[index]) {
    // Swap the new value with its parent
    int temp = vdata[(index - 1) / 2];
    vdata[(index - 1) / 2] = vdata[index];
    vdata[index] = temp;

    // Update the index to the parent's index
    index = (index - 1) / 2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.size() == 0) {
    return;
  }

  // Replace the root with the last element in the heap
  vdata[0] = vdata.back();
  vdata.pop_back();

  // Fix the heap property by comparing the new root to its children
  int index = 0;
  while (index * 2 + 1 < vdata.size()) {
    // Find the index of the smallest child
    int min_child_index = index * 2 + 1;
    if (index * 2 + 2 < vdata.size() && vdata[index * 2 + 2] < vdata[min_child_index]) {
      min_child_index = index * 2 + 2;
    }

    // If the parent is larger than the smallest child, swap them
    if (vdata[index] > vdata[min_child_index]) {
      int temp = vdata[index];
      vdata[index] = vdata[min_child_index];
      vdata[min_child_index] = temp;

      // Update the index to the smallest child's index
      index = min_child_index;
    } else {
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
