#pragma once

struct ArrayValue {
    int key;
    int value;
    ArrayValue(int key = 0, int value = 0) {
        this->key = key;
        this->value = value;
    }
};
