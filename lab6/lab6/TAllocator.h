#pragma once

#include <cstdlib>


class TAllocator {
public:
    TAllocator(size_t size, size_t count);
    void* allocate();
    void deallocate(void* pointer);
    bool has_free_blocks();

    ~TAllocator();
private:
    size_t _size;
    size_t _count;

    char * _used_blocks;
    void **_free_blocks;

    size_t _free_count;

};