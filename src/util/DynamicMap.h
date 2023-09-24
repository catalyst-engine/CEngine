#ifndef CATALYST_ENGINE_DYNAMIC_MAP_H
#define CATALYST_ENGINE_DYNAMIC_MAP_H
#pragma once

#include <vector>
#include "unordered_map"
#include "DoubleLinkedList.h"

template<typename K, typename V>
class DynamicMap {
private:
    std::unordered_map<K, V *> map;
    Util::Basic::DoubleLinkedList<V> array;
    size_t size = 0;
public:
    std::unordered_map<K, V> *getMap() {
        return &map;
    }

    Util::Basic::DoubleLinkedList<V> *getList() {
        return &array;
    }

    void clear() {
        array.clear();
        map.clear();
        size = 0;
    }

    void deleteKey(K key) {
        if (!map.contains(key)) {
            return;
        }
        V *value = map[key];
        map.erase(key);
        array.remove(value);
        size--;
    }

    void set(K key, V *value) {
        if (map.contains(key)) {
            int index = array.indexOf(get(key));
            array.replaceAt(index, value);
        } else {
            array.push(value);
        }
        map[key] = value;
        size++;
    }

    V *get(K key) {
        if (!map.contains(key)) {
            return nullptr;
        }
        return map[key];
    }

    std::vector<K> getKeys() {
        std::vector<K> keys;
        for (const auto &pair: map) {
            keys.push_back(pair.first);
        }
        return keys;
    };

    std::vector<V> getValues() {
        return map.enum_values();
    };

    int getSize() {
        return size;
    }

    bool has(K key) {
        return map.contains(key);
    }
};

#endif