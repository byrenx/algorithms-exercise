#include <iostream>

using namespace std;

int qsort(int array[], int first, int size);

int partition(int array[], int first, int size);

int main(){
    const int SIZE = 11;
    int array[SIZE] = {3,4,2,7,6,1,5,10,32,21,11};
    //cout<<partition(array, 0, 6)<<"\n";
    int count=qsort(array, 0, SIZE-1);

    for(int i=0;i<SIZE;i++){
      cout<<array[i]<<"\n";
    }

    cout<<"# of comparisons: "<<count;
    return 0;
}


int qsort(int array[], int first, int size){
  int pivot_index=0;
  int count1;
  int count2;
  int final_count;
  if(size-first <= 1){
    return 0;
  }
  pivot_index=partition(array, first, size);
  count1=qsort(array, 0, pivot_index);
  count2=qsort(array, pivot_index+1, size);
  if(size-first>1){
    final_count = (size-first)-1;
  }
  return final_count;
}

int partition(int A[], int first, int size){
  int i = first+1;
  int p = A[first];
  int temp = 0;

  for(int k=first+1; k<=size; k++){
    if(p>A[k]){
      //A[k] = A[k]+A[i];
      temp = A[k];
      A[k] = A[i];
      A[i] = temp;
      //A[i] = A[k]-A[i];
      //A[k] = A[k]-A[i];
      i++;
    }
  }
  A[first] = A[i-1];
  A[i-1] = p;
  return (i-1);
}
