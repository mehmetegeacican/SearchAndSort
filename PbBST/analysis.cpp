#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "PbBST.h"
void  timeAnalysis(){
    PbBST A;
    int a = 0;
    for(int i = 0; i < 15000 ; i++){
        for(int j = 1; j < 15000; j = j*2){
            a++;
        }
    }
    cout << "Part e - Time analysis of Binary Search Tree - part 1" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
    int arr[15000];
    for(int i = 0;i <= 15000;i++){
        arr[i] = 1 + rand() % 15000;
        clock_t begin_time = clock();
        A.insertKey(arr[i]);
        if((i % 1500 == 0) && (i >= 1500)){
            cout << i << "         " << begin_time << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "Part e - Time analysis of Binary Search Tree - part 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
   for(int i = 0;i<= 15000;i++){
        clock_t begin_time2 = clock();
        A.deleteKey(arr[i]);
        if((i % 1500 == 0) && (i >= 1500)){
            cout << i << "         " << begin_time2  << endl;
        }
   }
}
