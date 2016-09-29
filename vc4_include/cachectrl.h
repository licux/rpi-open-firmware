#ifndef CACHECTRL_H
#define CACHECTRL_H 1

#define CACHECTRL_IC0           1
#define CACHECTRL_IC1           2
#define CACHECTRL_L1_INSN       (CACHECTRL_IC0 | CACHECTRL_IC1)
#define CACHECTRL_DC0           4
#define CACHECTRL_DC1           8
#define CACHECTRL_L1_DATA       (CACHECTRL_DC0 | CACHECTRL_DC1)
#define CACHECTRL_L2            16
#define CACHECTRL_ALL           (CACHECTRL_L1_INSN | CACHECTRL_L1_DATA | \
                                 CACHECTRL_L2)

/* These are for the two-bit L2_CONT_OFF_l2_flush_mode field: we don't know
   what the other values are for.  */
#define L2_FLUSH_MODE_FLUSH             0
#define L2_FLUSH_MODE_INVALIDATE        2

extern void cachectrl_enable(unsigned flags);
extern void cachectrl_disable(unsigned flags);
extern void cachectrl_flush_range(unsigned flags, void *lo, size_t len);
extern void cachectrl_invalidate_range(unsigned flags, void *lo, size_t len);
extern void cachectrl_flush(unsigned flags);
extern void cachectrl_invalidate(unsigned flags);
#endif