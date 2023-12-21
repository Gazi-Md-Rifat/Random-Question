#include <bits/stdc++.h>
using namespace std;

void printData(list<string> add){
    list<string> :: iterator it = add.begin();
    for (it; it != add.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    list<string> web;
    string address;
    getline(cin, address);
    int n;
    cin >> n;
    cin.ignore();


    // sore address
    string data = "";
    for (int i = 0; i < address.size(); i++){
        if (data == "end"){
            break;
        }
        if (address[i] == ' '){
            web.push_back(data);
            data = "";
            continue;
        }
        data = data + address[i];
    }


    // command & act through command
    list<string> :: iterator track;
    list<string> :: iterator beg = web.begin();
    list<string> :: iterator end = web.end();
    for (int i = 0; i < n; i++){
        string command;
        getline(cin, command);
        if (command == "prev"){
            if (track == beg){
                cout << "Not Available";
            }
            else {
                track--;
                cout << *track;
            }
        }
        else if (command == "next"){
            list<string> :: iterator temp = end;
            if (track == --temp){
                cout << "Not Available";
            }
            else {
                track++;
                cout << *track;
            }
        }
        else {
            string add = command.substr(6, command.size());
            list<string> :: iterator ans = find(beg, end, add);
            if (ans != end){
                cout << *ans;
                track = ans;
            }
            else {
                cout << "Not Available";
            }
        }
        cout << endl;
    }

    // printData(web);    // print list called function

    return 0;
}