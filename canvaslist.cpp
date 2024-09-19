#include "canvaslist.h"
#include <iostream>

using namespace std;

// Constructor: Initializes an empty CanvasList
CanvasList::CanvasList() {
    list_size = 0;
    list_front = nullptr;
}

// Copy Constructor: Creates a deep copy of another CanvasList
CanvasList::CanvasList(const CanvasList& other) {
    list_front = nullptr;
    list_size = 0;
    
    // Iterate through the 'other' list and copy each shape
    ShapeNode* Node = other.list_front;
    while (Node != nullptr) {
        push_back(Node->value->copy());
        Node = Node->next;
    }

    list_size = other.list_size;
}

// Assignment Operator: Assigns another CanvasList to this one
CanvasList& CanvasList::operator=(const CanvasList& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;  
    }
    
    clear(); // Clear current list contents
    // Copy elements from the other list
    ShapeNode *otherNode = other.list_front; 
    while (otherNode != nullptr) { 
        push_back(otherNode->value->copy());
        otherNode = otherNode->next;
    }
    
    return *this;
}

// Destructor: Cleans up all nodes and shapes
CanvasList::~CanvasList() {
    clear();
}

// Clear: Removes all elements from the list
void CanvasList::clear() {
    // Delete each node in the list
    while (list_size != 0) {
        ShapeNode* Delete_Node = list_front;
        list_front = list_front->next;
        delete Delete_Node->value;
        delete Delete_Node;
        list_size--;
    }
}

// Insert After: Inserts a shape after a given index
void CanvasList::insert_after(int index, Shape* s) {
    // Check if the index is out of bounds
    if (index < 0 || index >= list_size || list_front == nullptr) {
        return;
    }

    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;

    // Traverse to the node at the given index
    ShapeNode* curr = list_front;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    // Insert the new node after the current node
    newNode->next = curr->next;
    curr->next = newNode;

    list_size++;
}

// Push Front: Adds a new shape to the front of the list
void CanvasList::push_front(Shape* s) {
    ShapeNode* Node = new ShapeNode;
    Node->value = s;
    Node->next = list_front;
    list_front = Node;
    list_size++;
}

// Push Back: Adds a new shape to the end of the list
void CanvasList::push_back(Shape* s) {
    ShapeNode *Node = new ShapeNode;
    Node->value = s;
    Node->next = nullptr;

    // Handle empty list case
    if (list_front == nullptr) {
        list_front = Node;
    } else {
        // Find the last node and attach the new node
        ShapeNode *currNode = list_front;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = Node;
    }
    list_size++;
}

// Remove At: Removes the shape at the specified index
void CanvasList::remove_at(int index) {
    // Do nothing if the index is out of range
    if (index < 0 || index >= list_size) {
        return;
    }

    // Handle the case where the first element is removed
    if (index == 0) {
        ShapeNode* temp = list_front;
        list_front = list_front->next;
        delete temp->value;
        delete temp;
    } else {
        // Find the node before the one to remove
        ShapeNode* currNode = list_front;
        for (int i = 0; i < index - 1; i++) {
            currNode = currNode->next;
        }
        ShapeNode* temp = currNode->next;
        currNode->next = temp->next;
        delete temp->value;
        delete temp;
    }
    list_size--;
}

// Remove Every Other: Removes every other shape in the list
void CanvasList::remove_every_other() {
    if (list_front == nullptr) {
        return;
    }

    ShapeNode* currNode = list_front;
    ShapeNode* prevNode = nullptr;
    int removeCurrent = 0;

    while (currNode != nullptr) {
        if (removeCurrent ==1) {
            prevNode->next = currNode->next;
            delete currNode->value;
            delete currNode;
            list_size--;
            currNode = prevNode->next;
        } else {
            prevNode = currNode;
            currNode = currNode->next;
        }
        removeCurrent = 1 - removeCurrent;
    }
}

// Pop Front: Removes and returns the first shape in the list
Shape* CanvasList::pop_front() {
    if (list_front == nullptr) {
        return nullptr;
    }
    ShapeNode* head = list_front;
    list_front = list_front->next;
    Shape* shape = head->value;
    delete head;
    list_size--;
    return shape;
}

// Pop Back: Removes and returns the last shape in the list
Shape* CanvasList::pop_back() {
    // Return nullptr if the list is empty
    if (list_front == nullptr) {
        return nullptr; 
    }

    // Special case: single element in the list
    if (list_front->next == nullptr) { 
        ShapeNode *tail = list_front;
        list_front = nullptr; 
        Shape *shape = tail->value;
        delete tail;
        list_size--;
        return shape; 
    }

    // Traverse to the last node
    ShapeNode *currNode = list_front; 
    ShapeNode *prevNode = nullptr; 
    while (currNode->next != nullptr) {
        prevNode = currNode; 
        currNode = currNode->next; 
    }

    // Remove the last node and return its shape
    prevNode->next = nullptr; 
    Shape *shape = currNode->value; 
    delete currNode; 
    list_size--; 
    return shape; 
}

// Front: Returns the first node in the list
ShapeNode* CanvasList::front() const {
    return list_front;
}

// Empty: Checks if the list is empty
bool CanvasList::empty() const {
    return list_size == 0;
}

// Size: Returns the number of elements in the list
int CanvasList::size() const {
    return list_size;
}

// Find: Returns the index of the shape with specified coordinates, -1 if not found
int CanvasList::find(int x, int y) const {
    int index = 0;
    ShapeNode *currNode = list_front;
    while (currNode != nullptr) {
        if (currNode->value->getX() == x && currNode->value->getY() == y) {
            return index;
        }
        currNode = currNode->next;
        index++;
    }
    return -1;
}

// Shape At: Returns the shape at a given index, nullptr if index is out of range
Shape* CanvasList::shape_at(int index) const {
    if (index < 0 || index >= list_size) {
        return nullptr;
    }
    ShapeNode *currNode = list_front;
    for (int i = 0; i < index; i++) {
        currNode = currNode->next;
    }
    return currNode->value;
}

// Draw: Prints the string representation of each shape in the list
void CanvasList::draw() const {
    ShapeNode *currentNode = list_front;
    while (currentNode != nullptr) {
        cout << currentNode->value->as_string() << endl;
        currentNode = currentNode->next;
    }
}

// Print Addresses: Prints the memory addresses of the nodes and shapes
void CanvasList::print_addresses() const {
    ShapeNode *currNode = list_front;
    while (currNode != nullptr) {
        cout << "Node Address: " << currNode << "    Shape Address: " << currNode->value << endl;
        currNode = currNode->next;
    }
}
