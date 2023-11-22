#include <vector>

template <typename T>
class heap {
public:
  void initializeMaxHeap(void) { buildMaxHeap(); }
  T getItem(int i) { return item_list[i]; }
  void insert(T value) { item_list.push_back(value); }
  int size(void) { return item_list.size(); }
  
  void heapsort(void) 
  {
    int size = item_list.size();
    for (int i = size / 2 -1; i >= 0; i--) {
      maxHeapify(i, size);
    }
  }

private:
  std::vector<T> item_list;
  int parent(int i) { return (i - 1) / 2; }
  int child_left(int i) { return 2 * i + 1; }
  int child_right(int i) { return 2 * i + 2; }
  
  void maxHeapify(int i, int size)
  {
    int largest = i;
    int l = child_left(i);
    int r = child_right(i);
    if (l < size && item_list[l] > item_list[largest]) { largest = l; }
    if (r < size && item_list[r] > item_list[largest]) { largest = r; }
    if (largest != i) {
      std::swap(item_list[i], item_list[largest]);
      maxHeapify(largest, size);
    }
  }
  
  void buildMaxHeap(void) 
  {
    int maxHeapSize = item_list.size();
    for (int i = maxHeapSize / 2 - 1; i >= 0; i--) {
      maxHeapify(i, maxHeapSize);
    }
  }
};
