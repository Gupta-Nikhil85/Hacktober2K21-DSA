// detect loop in linked list using floyd cycle detection
//ALGORITHM:
//Initialize : slow_p=head , fast_p = head
//move slow_p by one and fast_p by two . if these pointers meet ,
//then there is a loop

//code :
bool isLoop(Node *head){
    Node *slow_p=head,*fast_p=head;
    while(fast_p != NULL && fast_p->next != NULL){
        slow_p=slow_p->next;
        fast_p=fasp_p->next->next;
        if(slow_p==fast_p)
        return true;
    }
    return false;
}
 

