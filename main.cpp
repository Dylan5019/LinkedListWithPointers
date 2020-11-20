#include <iostream>

class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    const char* view() {
      return item;
    }

};

class LinkedList {

  private:

    ListItem* first_item;
    int list_length;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        current_item=next_item;
        next_item = current_item->nextItem();
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }

    
// Implemting itemAtPostion
    std::string get(int index){

      if(index <= length()-1){
      int count = 0;
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (current_item != nullptr) {
        if(count == index){
        return current_item->view();
        }
        count ++;
        current_item=next_item;
        next_item = current_item->nextItem();
       }
       return "NA";
      }
      return "NA";
    }


//Implemting insertAtPostion
  void insertAtPostion(int index, const char *newItem){
    if(index <= length()-1){
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      ListItem* previous_item = first_item;
     
      int count = 0;
      
      while (current_item != nullptr) {
         if(count == index){
           if(index == 0){
             first_item = new_item;
             new_item->setNextItem(current_item);
              list_length += 1;
             break;
           } else if(index == length()-1) {
             addListItem(new_item->view());
             break;
           }
         previous_item->setNextItem(new_item);
         new_item->setNextItem(current_item);
         list_length += 1;
         break;
         }
        count++;
        previous_item = current_item;
        current_item=next_item;
        next_item = current_item->nextItem();
      }
    }
  }


    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }

    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }

};

int main() {
  //Adding Items to list
  std::cout << "Adding items to the list..."<< "\n";
  LinkedList l("Sam");
  l.addListItem("Bob");
  l.addListItem("Helen");
  l.addListItem("Steve");
  l.outputList();
  std::cout << "List Length: ";
  l.outputLength();
  std::cout << "\n";

// Getting the data from a postion
  std::cout << "Getting item stored in Index..."; 
  std::cout << "\n";
  std::cout << l.get(2) + "\n";
  std::cout << "\n";

  //Inserting at a postion
  std::cout << "Inserting item at Index..." << "\n"; 
  l.insertAtPostion(2, "Roger");
  l.outputList();
  std::cout << "List Length: ";
  l.outputLength();
  std::cout << "\n";


}
