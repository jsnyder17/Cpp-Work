//*______ Joshua Snyder ______*//

#ifndef HASHMAP_H
#define HASHMAP_H

#include "Item.h"
#include <iostream>

template <class T>
class HashMap {
    public:
        HashMap() {
            count = 0;
        }
        virtual ~HashMap() {}

        void add(const T& DATA) {
            items[count] = Item<T>(DATA, count);
            count++;
        }
        void remove(const int& KEY) {
            for (int i = 0; i < count; i++) {
                if (items[count].key == KEY) {
                    count--;
                }
            }
        }
        void display() const {
            std::cout << "------ HASH MAP ------" << std::endl;

            for (int i = 0; i < count; i++) {
                std::cout << items[i].getData() << " | " << items[i].getHashKey() << std::endl;
            }

            std::cout << "---------------------" << std::endl;
        }

        int find(const int& KEY) const {
            int left, right, index;
            left = 0;
            right = 255;
            index = -1;
            bool found = false;

            while (left < right && index < 0) {
                if (items[left].getHashKey() == KEY) {
                    index = left;
                }
                else if (items[right].getHashKey() == KEY) {
                    index = right;
                }
                else {
                    left++;
                    right--;
                }
            }

            return index;
        }

    private:
        Item<T> items[256];
        int count;
};

#endif