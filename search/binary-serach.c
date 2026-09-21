#include<stdio.h>

int binary_search(const int arr[], int size, int target){

  int first = 0;
  int last = size - 1;
  int mid;

  while(first <= last){
    mid = first + (last - first) / 2;

    if(arr[mid] == target){
      return mid;
    }
    else if (target > arr[mid]){
      first = mid + 1;
    }
    else{
      last = mid - 1;
    }
  }

  return -1;
}

int main() {

  int arr[7] = {0, 1, 1, 2, 2, 3, 4};

  int a = binary_search(arr, 7, 3);

  printf("%d\n", a);

  return 0;
}