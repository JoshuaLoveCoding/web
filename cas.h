#ifndef CAS_H
#define CAS_H

static inline int
__cas(unsigned long *target, unsigned long cmp, unsigned long updated)
{
    char z;
    __asm__ __volatile__("lock cmpxchgl %2, %0; setz %1"
    : "+m" (*target),
    "=a" (z)
    : "q"  (updated),
    "a"  (cmp)
    : "memory", "cc");
    return (int)!z;
}

#endif
