#include "bit-vector.h"


Bitvector::Bitvector()
    :v_size{ 0 }
    ,v_capacity{ 1 }
    ,v_buff{ nullptr }
{
    allocate();
}

Bitvector::Bitvector(const size_t& size, const size_t& capacity, const unsigned* buff)
    :v_size{size}
    ,v_capacity{capacity} 
    ,v_buff{ nullptr} 
{
    allocate(buff);
}

Bitvector::~Bitvector()
{
    deallocate();
}

void Bitvector::set(const size_t& number, const size_t& bit) {
    if(number < 0 || number >= sizeof(unsigned) * v_size * bit_per_byte) {
        std::cout << "Illegal position!" << std::endl;
        return;
    }
    int wordSize = sizeof(unsigned) * bit_per_byte;
    int index = number/wordSize;
    int pos = wordSize - number % wordSize - 1;
    v_buff[index] |= (bit << pos);
}

size_t Bitvector::get(const size_t& number) {
    if(number < 0 || number >= sizeof(unsigned) * v_size * bit_per_byte) {
        std::cout << "Illegal position!" << std::endl;
        return 0;
    }
    int wordSize = sizeof(unsigned) * bit_per_byte;
    int index = number/wordSize;
    int pos = wordSize - number % wordSize - 1;
    int bit_required;
    bit_required = v_buff[index] & (1 << pos);
    if(!bit_required) { return 0;}
    return 1;
}

void Bitvector::print() const {
    for(size_t i = 0; i < v_size; ++i) {
        std::cout << v_buff[i] << " ";
    }
}

void Bitvector::allocate(const unsigned* buff) {
    v_buff = new unsigned[v_capacity];
    if(buff) {
        for(unsigned i = 0; i < v_size; ++i) {
            v_buff[i] = buff[i];
        }
    }
}
       
void Bitvector::deallocate() {
    delete[] v_buff;
}

size_t Bitvector::getSize() const {
    return v_size;
}

void Bitvector::setSize(const size_t size) {
    v_size = size;
}

size_t Bitvector::getCapacity() const {
    return v_capacity;
}

void Bitvector::setCapacity(const size_t capacity) {
    v_capacity = capacity;
}
