#include <vector>

template <typename T>
class heap {
public:
  void initializeMaxHeapSort(void) { maxHeapSort(); }
  T getItem(int i) { return item_list[i]; }
  void insert(T value) { item_list.push_back(value); }
  int size(void) { return item_list.size(); }
private:
  std::vector<T> item_list;
  int parent(int i) { return (i - 1) / 2; }
  int child_left(int i) { return 2 * i + 1; }
  int child_right(int i) { return 2 * i + 2; }
  void maxHeapify(int size, int i)
  {
    int largest = i;
    int l = child_left(i);
    int r = child_right(i);
    if (l < size && item_list[l] > item_list[largest]) { largest = l; }
    if (r < size && item_list[r] > item_list[largest]) { largest = r; }
    if (largest != i) {
      std::swap(item_list[i], item_list[largest]);
      maxHeapify(size, largest);
    }
  }
  void maxHeapSort(void) 
  {
    int N = this->size();
    for (int i = N / 2 - 1; i >= 9; i--)
      maxHeapify(i, N);
    for (int i = N - 1; i > 0; i--) {
      std::swap(item_list[0], item_list[i]);
      maxHeapify(i, 0);
    }
  }

};
