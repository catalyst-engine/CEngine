#ifndef CATALYST_ENGINE_DOUBLE_LINKED_LIST_H
#define CATALYST_ENGINE_DOUBLE_LINKED_LIST_H
#pragma once

#include <cstddef>

namespace Catalyst {
    template<typename T>
    struct ListItem {
        T *value;
        ListItem *next;
        ListItem *previous;

        explicit ListItem(T *value) : value(value), next(nullptr), previous(nullptr) {}
    };

    template<typename T>
    class List {
    private:
        Catalyst::ListItem<T> *start{};
        Catalyst::ListItem<T> *end{};
        Catalyst::ListItem<T> *iterator{};
        size_t length = 0;
    public:
        List() {
            start = nullptr;
            end = nullptr;
            iterator = nullptr;
        }

        size_t getLength() {
            return length;
        }

        void clear() {
            start = nullptr;
            end = nullptr;
            iterator = nullptr;
            length = 0;
        }

        T *get(size_t index) {
            if (index >= length) {
                return nullptr;
            }
            ListItem<T> *item = getItem(index);
            if (item != nullptr) {
                return item->value;
            }
            return nullptr;
        }

        Catalyst::ListItem<T> *getItem(size_t index) {
            int i = 0;
            ListItem<T> *current = start;
            while (i < index && current != nullptr) {
                i++;
                current = current->next;
            }
            return current;
        }

        void remove(T *item) {
            ListItem<T> *current = start;

            while (current) {
                if (current->value == item) {
                    if (current->previous) {
                        current->previous->next = current->next;
                    } else {
                        start = current->next;
                    }

                    if (current->next) {
                        current->next->previous = current->previous;
                    } else {
                        end = current->previous;
                    }

                    delete current;
                    length--;
                    return;
                }
                current = current->next;
            }
        }

        void replaceAt(size_t index, T *value) {
            ListItem<T> *pItem = getItem(index);
            if (pItem != nullptr) {
                pItem->value = value;
            }
        }

        void removeAt(size_t index) {
            ListItem<T> *current = start;
            int currentIndex = 0;

            while (current && currentIndex < index) {
                current = current->next;
                currentIndex++;
            }

            if (current) {
                if (current->previous) {
                    current->previous->next = current->next;
                } else {
                    start = current->next;
                }

                if (current->next) {
                    current->next->previous = current->previous;
                } else {
                    end = current->previous;
                }

                delete current;
                length--;
            }
        }

        bool includes(T *item) {
            ListItem<T> *current = start;
            while (current != nullptr) {
                if (current->value == item) {
                    return true;
                } else {
                    current = current->next;
                }
            }
            return false;
        }

        int indexOf(T *item) {
            int i = 0;
            ListItem<T> *current = start;

            while (current != nullptr) {
                if (current->value == item) {
                    return i;
                } else {
                    i++;
                    current = current->next;
                }
            }
            return -1;
        }

        void push(T *item) {
            ListItem<T> *newNode = new ListItem(item);

            if (!start) {
                start = newNode;
                end = newNode;
            } else {
                newNode->previous = end;
                end->next = newNode;
                end = newNode;
            }
            length++;
        }

        void pop() {
            if (end) {
                ListItem<T> *prevTail = end->previous;
                if (prevTail) {
                    prevTail->next = nullptr;
                    delete end;
                    end = prevTail;
                } else {
                    delete end;
                    start = nullptr;
                    end = nullptr;
                }
            }
            length--;
        }

        void iterate() {
            iterator = start;
        }

        bool hasNext() {
            return iterator != nullptr;
        }

        T *next() {
            if (iterator == nullptr) {
                return nullptr;
            }
            T *value = iterator->value;
            iterator = iterator->next;
            return value;
        }

        Catalyst::ListItem<T> *getFirst() {
            return start;
        }

        Catalyst::ListItem<T> *getLast() {
            return end;
        }
    };
}

#endif