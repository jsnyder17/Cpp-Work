//*_______ Joshua Snyder ______*//

#ifndef ITEM_H
#define ITEM_H

template <class T>
class Item {
    public:
        Item() {}
        Item(const T& DATA, const int& HASH_KEY)  {
            this->data = DATA;
            this->hashKey = HASH_KEY;
        }
        virtual ~Item() {}

        T getData() const {
            return data;
        }
        int getHashKey() const{
            return hashKey;
        }

        void setData(const T& DATA) {
            this->data = DATA;
        }
        void setHashKey(const int& HASH_KEY) {
            this->hashKey = HASH_KEY;
        }

    private:
        T data;
        int hashKey;
};

#endif