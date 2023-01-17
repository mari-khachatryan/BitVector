#include <iostream>
#include "bit-vector.h"


int main() {
    const size_t size = 3;
    const size_t capacity = 4;
    unsigned arr[size] {1, 1, 1};
    Bitvector v(size, capacity, arr);
    v.set(42, 1);
    std::cout << "Array already modified" << std::endl;
    v.print();
    std::cout << "\nthe bit in that position is: " << v.get(42) << std::endl;
    
    return 0;
}
