#include <iostream>
#include <vector>

using namespace std;
static const int SIZE = 9;

void bubbleSort(int alist[]) {
  int temp = 0;
  for (int i = SIZE - 1; i > -1; --i) {
    for (int j = 0; j < i; ++j) {
      if (alist[j] > alist[j + 1]) {
        temp = alist[j];
        alist[j] = alist[j + 1];
        alist[j + 1] = temp;
      }
    }
  }
}

void selectionSort(int alist[]) {
  for (int i = SIZE - 1; i > -1; --i) {
    int maxIndex = 0;
    for (int j = 1; j <= i; ++j) {
      if (alist[j] > alist[maxIndex]) {
        maxIndex = j;
      }
    }
    int temp = alist[i];
    alist[i] = alist[maxIndex];
    alist[maxIndex] = temp;
  }
}

void insertSort(int alist[]) {
  for (int i = 1; i < SIZE; ++i) {
    int index = i;
    while(index > 0 && (alist[index] < alist[index - 1])) {
      int temp = alist[index];
      alist[index] = alist[index - 1];
      alist[index - 1] = temp;
      --index;
    }
  }
}

void gapInsertionSort(int alist[], int start, int gap) {
  for (int i = start + gap; i < SIZE; i+=gap) {
    int currentValue = alist[i];
    int position = i;

    while((position >= gap) && (alist[position - gap] >= currentValue)) {
      alist[position] = alist[position - gap];
      position -= gap;
    }
    alist[position] = currentValue;
  }
}

void shellSort(int alist[]) {
  int sublistCount = SIZE / 2;
  while(sublistCount > 0) {
    for (int i = 0; i < sublistCount; ++i) {
      gapInsertionSort(alist, i, sublistCount);
    }
    sublistCount /= 2;
  }
}

void mergeSort(int alist[], int size) {
  if (size > 1) {
    int middle = size / 2;
    int left[middle];
    for (int i = 0; i < middle; ++i) {
      left[i] = alist[i];
    }
    int right[size - middle];
    for(int i = 0; i < (size - middle); ++i) {
      right[i] = alist[i + middle];
    }

    mergeSort(left, middle);
    mergeSort(right, size - middle);

    int i = 0, j = 0, k = 0;
    cout << "concatonate " << endl;
    while((i < middle) && (j < size - middle)) {
      if (left[i] < right[j]) {
        alist[k] = left[i];
        ++i;
      }else {
        alist[k] = right[j];
        ++j;
      }
      ++k;
    }

    while(i < middle) {
      alist[k] = left[i];
      ++i;
      ++k;
    }

    while(j < size - middle) {
      alist[k] = right[j];
      ++j;
      ++k;
    }
  }
}

int partition(int alist[], int first, int last) {
  int pivotValue = alist[first];
  int leftMark = first + 1;
  int rightMark = last;

  while (true) {
    if ((leftMark <= rightMark) && (alist[leftMark] <= pivotValue)) {
      ++leftMark;
    }
    if ((leftMark <= rightMark) && (pivotValue <= alist[rightMark])) {
      --rightMark;
    }

    if (leftMark > rightMark) break;

    int temp = alist[leftMark];
    alist[leftMark] = alist[rightMark];
    alist[rightMark] = temp;
  }

  int temp = alist[first];
  alist[first] = alist[rightMark];
  alist[rightMark] = temp;

  return rightMark;
}

void quickSortHelper(int alist[], int first, int last) {
  if (first < last) {
    int splitpoint = partition(alist, first, last);
    quickSortHelper(alist, first, splitpoint - 1);
    quickSortHelper(alist, splitpoint + 1, last);
  }
}

void quickSort(int alist[]) {
  quickSortHelper(alist, 0, SIZE - 1);
}

int main() {
  int alist[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
  quickSort(alist);
  for (int i = 0 ; i < SIZE; ++i) {
    cout << alist[i] << endl;
  }
}
