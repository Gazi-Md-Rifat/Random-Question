#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int cls, id, math_mark, eng_mark;
    char section;
};

void printFunction(Student arr[], int n){

    for (int j = 0; j < n - 1; j++){
        for (int i = 0; i < n - j - 1; i++){
            if (arr[i].eng_mark < arr[i + 1].eng_mark){
                swap(arr[i], arr[i + 1]);
            }
            else if (arr[i].eng_mark == arr[i + 1].eng_mark){
                if (arr[i].math_mark < arr[i + 1].math_mark){
                    swap(arr[i], arr[i + 1]);
                }
                else if (arr[i].math_mark == arr[i + 1].math_mark){
                    if (arr[i].id > arr[i + 1].id){
                        swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << arr[i].name << " " << arr[i].cls << " " << arr[i].section << " " << arr[i].id << " " << arr[i].math_mark << " " << arr[i].eng_mark << endl;
    }

}

int main(){

    int n;
    cin >> n;
    Student data[n];
    for (int i = 0; i < n; i++){
        Student temp;
        cin >> temp.name >> temp.cls >> temp.section >> temp.id >> temp.math_mark >> temp.eng_mark;
        data[i] = temp;
    }



    printFunction(data, n);

    return 0;
}