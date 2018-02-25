#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode * next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};
void printList(ListNode * head){
    while(head!= NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


ListNode * reverseList(ListNode * head){
    if(head==NULL || head->next == NULL) return head;

    ListNode * prev = NULL;
    ListNode * current = head;
    ListNode * next = NULL;

    while(current->next != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    return current;
}
 int getLength(ListNode * head){
     int count = 0;
     while(head!= NULL){
         count++;
         head = head->next;
     }
     return count;
 }

int palindrome(ListNode* A) {
    if(A==NULL) return 0;
    int length = getLength(A);
    if(length == 1) return 1;
    length = (length+1)/2;
    
    ListNode * temp = A;
    ListNode * prev = NULL;
    while(length--){
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    temp = reverseList(temp);
    
    while(temp!= NULL && A!= NULL){
        if(temp->val != A->val) return 0;
        temp = temp->next;
        A = A->next;
    }
    return 1;
}

ListNode * remove_duplicates_from_sorted_list(ListNode * head){
    if(head==NULL || head->next == NULL) return head;
    ListNode * current = head;
    while(current != NULL && current->next != NULL){
        if(current->val == current->next->val){
            ListNode * next = current->next;
            current->next = next->next;
            delete next;
        }
        else{
            current = current->next;
        }
    }
    return head;
}

ListNode * removeDuplicates2(ListNode * head){
    if(head==NULL || head->next == NULL) return head;
    ListNode * current = head;
    ListNode * prev = NULL;
    while(current != NULL && current->next != NULL){
        bool flag = false;
        while(current->val == current->next->val){
            ListNode * next = current->next;
            current->next = next->next;
            delete next;
            flag = true;
        }
        if(flag == true){
            if(prev != NULL){
                ListNode * temp = current;
                prev->next = current->next;
                delete current;
            }
            else{
                ListNode * temp = current;
                current = current->next;
                delete temp;
                head = temp;
            }
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return head;
}

int main(){
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    printList(head);
    //head = reverseList(head);
    //head = remove_duplicates_from_sorted_list(head);
    head = removeDuplicates2(head);
    printList(head);
    return 0;
}