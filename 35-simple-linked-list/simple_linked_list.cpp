#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    Element* new_element = new Element(entry);
    new_element->next = head;
    head = new_element;
    ++current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    int value{head->data};
    Element* old_head = head;
    head = head->next;
    delete(old_head);
    --current_size;
    return value;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    if (head != nullptr) {
        Element* prev_element = head;
        Element* current_element = head->next;
        Element* next_element;
        head->next = nullptr;
        head = nullptr;
        while (head == nullptr) {
            next_element = current_element->next;
            current_element->next = prev_element;
            if (next_element != nullptr) {
                prev_element = current_element;
                current_element = next_element;
            } else {
                head = current_element;
            }
        }
    }
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    Element* destructor;
    while (head != nullptr) {
        destructor = head;
        head = head->next;
        delete destructor;
    }
}

}  // namespace simple_linked_list
