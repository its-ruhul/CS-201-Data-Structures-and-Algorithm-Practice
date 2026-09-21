#include<stdio.h>
#include<limits.h>

void selection_sort(int arr[], int n){

  for(int i = 0; i < n-1; i++){

    int min = arr[i];
    int mix = i;

    for(int j = i+1; j < n; j++){
      if(arr[j] < min){
        min = arr[j];
        mix = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[mix];
    arr[mix] = temp;
  }

  return;
}

int main() {

  int arr[7] = {5, 2, 9, 4, 1, 3, 7};

  selection_sort(arr, 7);

  for(int i = 0; i < 7; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}