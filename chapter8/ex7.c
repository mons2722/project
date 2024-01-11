#include <stdio.h>
#include <stdlib.h>

#define MAXBYTES 10240
#define NALLOC 1024

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
};

union header base;
union header *freep = NULL;

union header *morecore(unsigned nu) {
    char *cp = (char *)malloc(nu * sizeof(union header));
    if (cp == NULL)
        return NULL;

    union header *up = (union header *)cp;
    up->s.size = nu;
    free((void *)(up + 1));
    return freep;
}

void *mymalloc(unsigned nbytes) {
    union header *p, *prevp;
    unsigned nunits = (nbytes + sizeof(union header) - 1) / sizeof(union header) + 1;

    if (nbytes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate more than %u bytes\n", MAXBYTES);
        return NULL;
    }

    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }

        if (p == freep)
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

void myfree(void *ap) {
    union header *bp = (union header *)ap - 1;
    union header *p;

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;

    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;

    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;

    freep = p;
}

int main(void) {
    int *p = mymalloc(1000);

    if (p == NULL) {
        printf("mymalloc returned NULL\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        printf("%08X ", p[i]);
        if (i % 8 == 7) {
            printf("\n");
        }
    }

    printf("\n");
    myfree(p);
    return 0;
}

