#ifndef CATALYST_ENGINE_LINKEDLIST_H
#define CATALYST_ENGINE_LINKEDLIST_H


#include <cstdarg>
#include <cstdlib>

namespace util {
    namespace basic {
        template<typename T>
        struct ListItem {
            T *value;
            ListItem *next;
            ListItem *previous;

             explicit ListItem(T* value) : value(value), next(nullptr), previous(nullptr) {}
        };

        template<typename T>
        class LinkedList {
        public:
            size_t Length() {
                return length;
            }

            T* Get(size_t index) {
                if (index >= length) {
                    return nullptr;
                }
                ListItem<T> *item = GetItem(index);
                if (item != nullptr) {
                    return item->value;
                }
                return nullptr;
            }

            ListItem<T>* GetItem(size_t index) {
                int i = 0;
                ListItem<T> *current = start;
                while (i < index && current != nullptr) {
                    i++;
                    current = current->next;
                }
                return current;
            }

            void Add(size_t index, T *item) {
                if (index > length) {
                    return;
                }
                if (length == 0) {
                    Push(item);
                    return;
                }
                auto* newItem = new ListItem<T>(*item);

                if (index == 0) {
                    start->previous = newItem;
                    newItem->next = start;
                    start = newItem;
                    return;
                }
                ListItem<T>* atIndex = GetItem(index);
                atIndex->previous->next = newItem;
                newItem->previous = atIndex->previous;
                newItem->next = atIndex;
                atIndex->previous = newItem;
                length++;
            }

            void Remove(size_t index) {
                if (length == 0 || index > length) {
                    return;
                }
                if (index == 0) {
                    start = start->next;
                    return;
                }
                if (index == length) {
                    Pop();
                    return;
                }
                ListItem<T> atIndex = *GetItem(index);
                atIndex.previous->next = atIndex.next;
                length--;
            }

            void Push(T *item) {
                auto* newItem = new ListItem<T>(item);
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

            bool Includes(T item) {
                ListItem<T> *current = start;
                while (current != nullptr) {
                    if (current == item) {
                        return true;
                    } else {
                        current = current->next;
                    }
                }
                return false;
            }

            size_t IndexOf(T item) {
                int i = 0;
                ListItem<T> *current = start;

                while (current != nullptr) {
                    if (current == item) {
                        return i;
                    } else {
                        i++;
                        current = current->next;
                    }
                }
                return -1;
            }

            T *Pop() {
                if (end->previous != nullptr && length > 1) {
                    ListItem<T> *newEnd = end->previous;
                    end->previous->next = nullptr;
                    end = newEnd;
                } else if (length == 1) {
                    start = nullptr;
                    end = nullptr;
                }
                length--;
            }

        private:
            util::basic::ListItem<T> *start = nullptr;
            util::basic::ListItem<T> *end = nullptr;
            size_t length = 0;
        };
    }
}

#endif
