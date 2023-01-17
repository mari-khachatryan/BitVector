#ifndef INCLUDE_BIT_VECTOR
#define INCLUDE_BIT_VECTOR

#include <iostream>

class Bitvector{
	public:

        static const int bit_per_byte = 8;

        Bitvector();
        Bitvector(const size_t& size, const size_t& capacity, const unsigned* buff);
        ~Bitvector();

        size_t getSize() const;
        void setSize(const size_t);
        size_t getCapacity() const;
        void setCapacity(const size_t);

        void set(const size_t&, const size_t&);
        size_t get(const size_t&);
        void print() const;

    private:
        void allocate(const unsigned* = nullptr);
        void deallocate();

    private:
        size_t v_size;
        size_t v_capacity;
        unsigned* v_buff;
};

#endif /*INCLUDE_BIT-VECTOR*/
