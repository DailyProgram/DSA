//
// Created by pda on 07.04.19.
//
#include <iostream>
#include "Circle_queue_exit.h"

Circle_queue_exit::Circle_queue_exit(unsigned int size) {
    const unsigned int def_size = 10;
    const int one = 1;

    if (size <= one) {
        max_l = def_size;
    } else { max_l = size; }

    vector = new struct element[max_l + one];
    left = 0;
    right = max_l + one;

}

Circle_queue_exit::~Circle_queue_exit() {
    delete[] vector;
}


unsigned int Circle_queue_exit::add(element el) {
    //add fist element
    if (left == 0 && right == max_l + 1) {
        right = left;
        vector[right].priority = el.priority;
        vector[right].data = el.data;
    } else {
        if (length() == max_l) { return 1; }
        right++;
        vector[(right + max_l) % max_l].data = el.data;
        vector[(right + max_l) % max_l].priority = el.priority;
    }
    return 0;
}

unsigned int Circle_queue_exit::print() {
    if (length() == 0) { return 2; }//queue empty

    cout << "head=" << (left + max_l) % max_l << " tail=" << (right + max_l) % max_l << endl;

    for (int i = left; i <= right; i++) {
        cout << "|" << vector[(i + max_l) % max_l].priority << vector[(i + max_l) % max_l].data;

    }
    cout << endl;
    for (int i = left; i <= right; i++) {
        cout << "|" << "#" << (i + max_l) % max_l;
    }
    cout << endl;
}

unsigned int Circle_queue_exit::length() {
    if (right - left + 1 > max_l) { return 0; }
    else return (right - left + 1);
}

unsigned int Circle_queue_exit::del() {

    if (length() == 0) { return 2; }//queue emptyS


    if (length() == 1) {
        left = 0;
        right = max_l;
    } else {

        int num_priority = left;

        for (int i = left; i <= right; i++) {
            if (vector[(i + max_l) % max_l].priority > vector[num_priority].priority) {
                num_priority = i;
            }
        }

        if (num_priority > (left + right) / 2) { move_left(num_priority); }
        else { move_right(num_priority); }
    }
    return 0;

}

element Circle_queue_exit::read() {
    if (length() == 0) {
        element empty;
        empty.data = "empty";
        empty.priority = 0;
        return empty;
    }

    int num_priority = left;

    for (int i = left; i <= right; i++) {

        if (vector[(i + max_l) % max_l].priority >= vector[num_priority].priority) {
            num_priority = i;
        }
    }

    return vector[num_priority];

}

void Circle_queue_exit::move_left(const unsigned int pos) {

    for (int i = 0; i < right - pos; i++) {
        vector[i + pos] = vector[i + pos + 1];
    }

    right = right - 1;

}

void Circle_queue_exit::move_right(const unsigned int pos) {

    for (int i = 0; i < pos - left; i++) {
        vector[pos - i] = vector[pos - i - 1];
    }

    left = left + 1;

}

Circle_queue_exit::Circle_queue_exit(const Circle_queue_exit &obj) {

    max_l = obj.max_l;
    vector = new struct element[max_l + 1];

    for (int i = 0; i < max_l + 1; i++) {
        vector[i] = obj.vector[i];
    }

    right = obj.right;
    left = obj.left;
}

Circle_queue_exit &Circle_queue_exit::operator=(Circle_queue_exit &obj) {

    if (obj.length() == 0) {
        left = 0;
        right = max_l;
    } else {
        if (obj.max_l <= max_l) {
            for (int i = 0; i <= obj.max_l; i++) {
                vector[i] = obj.vector[i];
            }

            left = obj.left;
            right = obj.right;

        } else {

            for (int i = obj.left; i < max_l + obj.left; i++) {
                vector[i - obj.left] = obj.vector[i];
            }

            left = 0;
            right = max_l - 1;

        }
    }
    return *this;
}