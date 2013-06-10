
#ifndef LINKED_LIST
#define LINKED_LIST

using namespace std;

template <class Obj>
class ObjectNode{
       public:
              Obj value;
              ObjectNode *next;
     
             ObjectNode(const Obj val,ObjectNode *p=0){
                   value=val;
                   next=p;                           
             }
};

template <class Obj>
class LinkedList{
      private:
             ObjectNode<Obj> *head;
             ObjectNode<Obj> *tail;
             int counter;
      public:
             ~LinkedList(){}
             LinkedList(){
                  counter=0;
             }
             void addToHead(const Obj val);
             void addToTail(const Obj val);
             void insertAfter(const Obj val,Obj nodeval);
             void insertBefore(const Obj val,Obj nodeval);
             Obj removeFromHead();
             Obj removeFromTail();
             bool isEmpty();
};

template <class Obj>
void LinkedList<Obj>::addToHead(const Obj val){
     head=new ObjectNode<Obj>(val,head);
     if(tail==0)
          tail=head;
     counter++;
}
template <class Obj>
void LinkedList<Obj>::addToTail(const Obj val){
     ObjectNode<Obj> *p=new ObjectNode<Obj>(val);
     
     if(head==0)
         head=tail=p;
     else{
          tail->next=p;
          tail=p;
     }
     counter++;
}
template <class Obj>
void LinkedList<Obj>::insertAfter(const Obj val,Obj nodeval){
     
     ObjectNode<Obj> *pred;
     ObjectNode<Obj> *succ;
     
     for(pred=head,succ=head->next;succ!=tail;pred=pred->next,succ=succ->next){
         if(pred->value==nodeval){
               ObjectNode<Obj> *newNode=new ObjectNode<Obj>(val);
               pred->next=newNode;
               newNode->next=succ;
               return;                       
         }                                                                                 
     }
    
}
template <class Obj>
void LinkedList<Obj>::insertBefore(const Obj val,Obj nodeval){
          ObjectNode<Obj> *pred;
          ObjectNode<Obj> *succ;
          for(pred=head,succ=head->next;succ!=tail;pred=pred->next,succ=succ->next){
               if(succ->value==nodeval){
                  ObjectNode<Obj> *newNode=new ObjectNode<Obj>(val);
                  pred->next=newNode;
                  newNode->next=succ; 
                  return;                     
               }
          }
}
template <class Obj>
Obj LinkedList<Obj>::removeFromHead(){
    Obj item=head->value;
    ObjectNode<Obj> *tmp=head;
    if(head==tail)
        head=tail=0;
    else
         head=head->next;
    delete tmp;
    counter--;
    return item;
}
template <class Obj>
Obj LinkedList<Obj>::removeFromTail(){
     Obj item=0;
     if(head==tail)//if theres only one item on list
         head=tail=0;
     else{
          ObjectNode<Obj> *pred;
          for(pred=head;pred->next!=tail;pred=pred->next);
          item=tail->value;
          delete tail;
          tail=pred;
          tail->next=0;    
     }
     counter--;
     return item;
}
template <class Obj>
bool LinkedList<Obj>::isEmpty(){
     if(counter==0 || head==0){
           return 1;
     }else{
           return 0;
     }      
}
#endif
