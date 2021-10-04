#include <iostream>
#include "list.h"
using namespace std;

int main(){
    List l;
    
    l.push_front(0);
    l.push_back(1);
    l.push_back(5);
    l.insert(-50,0);
    l.insert(2,3);
    l.insert(555,5);
    Node* head = l.begin();

    while(head!=NULL){
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;

    // l.pop_front();

    // head = l.begin();
    // while(head!=NULL){
    //     cout<<head->getData()<<"->";
    //     head=head->next;
    // }
    // cout<<endl;

    // l.pop_back();

    // head = l.begin();
    // while(head!=NULL){
    //     cout<<head->getData()<<"->";
    //     head=head->next;
    // }
    // cout<<endl;

    // l.remove(4);
    // head = l.begin();

    // while(head!=NULL){
    //     cout<<head->getData()<<"->";
    //     head=head->next;
    // }
    // cout<<endl;

    head=l.reverse();

    while(head!=NULL){
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;
    // cout<<"Enter Key To Be Searched:- ";
    // int key;
    // cin>>key;
    // if(l.recursiveSearch(key)!=-1){
    //     cout<<"Number Found at index "<<l.recursiveSearch(key)<<endl;
    // }
    // else{
    //     cout<<"Number Not Found!"<<endl;
    // }
    

    return 0;
}