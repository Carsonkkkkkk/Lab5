#include <iostream>
#include <string>

struct Node{  
    std::string data;  
    Node *next;  
};  

class Lilist{  
public:  
    Lilist(){head = NULL;}
    void add(std::string item);
    void show();
    Node* search(std::string target){
        Node* cursor = head;
        if(cursor -> data == target) return cursor;
        while(cursor->next != nullptr){
            cursor = cursor->next;
            if(cursor -> data == target) return cursor;
        }
        return nullptr;
    }
    void move_front_to_back(){
        if(head->next == nullptr) return;

        Node* first = head;
        head = head->next;

        first->next = nullptr;

        Node* last = head;
        while(last->next != nullptr) last = last->next;
        last->next = first;
    }
    
private:  
    Node *head;  
};  

void Lilist::add(std::string item){  
    Node * tmp;  

    if(head == NULL){  
        head = new Node;  
        head -> data = item;  
        head -> next = NULL;  
    }  
    else{  
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next);
        // this loop simply advances the pointer to the last node in the list  
                    
        tmp -> next = new Node;  
        tmp = tmp -> next;  
        tmp -> data = item;  
        tmp -> next = NULL;  
    }  
}    

void Lilist::show(){  
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next)  
        std::cout << tmp -> data << "  ";  
}  