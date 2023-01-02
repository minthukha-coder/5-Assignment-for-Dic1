//
// Created by User on 31/12/2022.
//
#include"stdio.h"
#include"math.h"

int min(int first,int second){
    if (second > first){
        return first;
    }else{
        return second;
    }
}



int jumpSearch(int arr[],int size,int key) {
    int step = size / 2;
    int previous = 0;

    if (arr[step-1] == key) {
        return (step-1);
    }


    while (arr[min(step, size) - 1] < key) {
        previous = step;
        step += size / 2;

        if (previous >= size) {
            return -1;
        }
    }
//    for (int j = previous; j < step;j++){
//        if (arr[j] == key){
//            return j;
//        }
//    }

    if (arr[min(step, size) - 1] > key) {
        int low = 0;
        int high = step;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (key == arr[mid]) {
                return mid;
            } else if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    } else {
        int low = previous;
        int high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (key == arr[mid]) {
                return mid;
            } else if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}


int main(){
    int arr[] = {2,5,7,9,11,13,15,17,19,21,23,25,29};

    int size = sizeof(arr)/sizeof(arr[0]);
    int toFind = 13;
    int indexNumber = jumpSearch(arr,size,toFind);
    if (indexNumber != -1){
        printf("We found\n");
    printf("Found at index %d: data: %d\n",indexNumber,arr[indexNumber]);

}else{
       printf("Not found\n");
    }
    return 0;
}
