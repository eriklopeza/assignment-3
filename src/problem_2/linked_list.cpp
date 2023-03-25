#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */

    // auto is easier to read and will be correct
    // check if list is empty
    // else push in front of first node and increment size
    auto node = new ListNode<T> (value);
    if(head->next == nullptr) {
        head->next = node;
    }
    else {
        node->next = head->next;
        head->next = node;
    }
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */

    // create new node, iterate the linked list until you are at the end
    auto node = new ListNode<T>(value);
    ListNode<T> *curr = head;

    // if list is empty, set head to new node and return
    if (head == nullptr) {
        head = node;
        num_of_element++;
        return;
    }


    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
    num_of_element++;

}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */

    // keep track of previous to last to cut node off
    ListNode<T> *prev = head;
    ListNode<T> *curr = head->next;

    if (curr == nullptr) {
        return;
    }

    // delete only element in the list
    if (curr->next == nullptr) {
        head->next = nullptr;
        delete curr;
        num_of_element--;
        return;
    }

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
    num_of_element--;

}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    ListNode<T> *curr = head->next;

    if (curr == nullptr) {
        return;
    }

    // only element in the list
    if (curr->next == nullptr) {
        head->next = nullptr;
        delete curr;
        num_of_element--;
        return;
    }

    head->next = curr->next;
    delete curr;
    num_of_element--;


}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     */

    // check if empty list
    if (num_of_element == 0) {
        return;
    }

    // create two pointers, to have access to the previous when we remove
    ListNode<T> *p1 = head;
    ListNode<T> *p2 = head->next;

    // iterate the list
    // remove if you encounter the value node, update nodes and increment
    while (p2 != nullptr) {
        if (p2->val == val) {
            p1->next = p2->next;
            delete p2;
            p2 = p1->next;
            num_of_element--;
        }
        else {
            p1 = p2;
            p2 = p2->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */

    // cast List ot into LinkedList type
    const LinkedList<T> &other_list = dynamic_cast<const LinkedList<T>&>(ot);

    // we will merge them with this new list and assign this linkedlist to point to mergedlist
    // we will also update the length
    LinkedList<T> *merged_list = new LinkedList<T>();

    // initialize our pointers to both lists
    ListNode<T> *p1 = head->next;
    ListNode<T> *p2 = other_list.head->next;

    // add the smaller value of the two until the length of the shortest list
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val <= p2->val) {
            merged_list->push_back(p1->val);
            p1 = p1->next;
        }
        else {
            merged_list->push_back(p2->val);
            p2 = p2->next;
        }
    }

    // these loops will check for if any, list that still has nodes left
    while (p1 != nullptr) {
        merged_list->push_back(p1->val);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        merged_list->push_back(p2->val);
        p2 = p2->next;
    }

    // update this
    this->head  = merged_list->head;
    this->num_of_element = merged_list->num_of_element;

//    delete merged_list;
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */

    // checks for lengths of 0, 1 which theres nothing to do in this case
    if (head->next == nullptr || head->next->next == nullptr) {
        return;
    }

    // we want to have access to the previous node at each iteration starting with the second node
    ListNode<T> *p1 = head->next;
    ListNode<T> *p2 = p1->next;

    // loop through list
    // at each iteration that we have two nodes to reverse we will:
    // swap the direction of the two to be reversed
    // we will insert the last node to the front and set p2 back to end (p2's original next)
    while (p2 != nullptr) {
        p1->next = p2->next;
        p2->next = head->next;
        head->next = p2;
        p2 = p1->next;
    }

}