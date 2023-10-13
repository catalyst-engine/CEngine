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
        List(){
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

        void add(size_t index, T *item) {
            if (index > length) {
                return;
            }
            if (length == 0) {
                Push(item);
                return;
            }
            auto *newItem = new ListItem<T>(*item);

            if (index == 0) {
                start->previous = newItem;
                newItem->next = start;
                start = newItem;
                return;
            }
            ListItem<T> *atIndex = getItem(index);
            atIndex->previous->next = newItem;
            newItem->previous = atIndex->previous;
            newItem->next = atIndex;
            atIndex->previous = newItem;
            length++;
        }

        void remove(T *item) {
            int index = indexOf(item);
            if (index < 0) {
                return;
            }
            removeAt(index);
        }

        void replaceAt(size_t index, T *value) {
            ListItem<T> *pItem = getItem(index);
            if (pItem != nullptr) {
                pItem->value = value;
            }
        }

        void removeAt(size_t index) {
            if (length == 0 || index > length) {
                return;
            }
            if (index == 0) {
                start = start->next;
                return;
            }
            if (index == length) {
                pop();
                return;
            }
            ListItem<T> atIndex = *getItem(index);
            atIndex.previous->next = atIndex.next;
            length--;
        }

        void push(T *item) {
            auto *newItem = new ListItem<T>(item);
            newItem->value = item;
            newItem->previous = nullptr;
            newItem->next = nullptr;

            if (length > 0) {
                newItem->previous = end;
                end->next = newItem;
                end = newItem;
            } else {
                end = start = newItem;
            }
            length++;
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

        T *pop() {
            T *removed = nullptr;
            if (end->previous != nullptr && length > 1) {
                removed = end->value;
                ListItem<T> *newEnd = end->previous;
                end->previous->next = nullptr;
                end = newEnd;
            } else if (length == 1) {
                removed = end->value;
                start = nullptr;
                end = nullptr;
            }
            length--;
            return removed;
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