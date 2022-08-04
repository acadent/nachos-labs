
#include "syscall.h"

int
main()
{
    Create("test-file-xyz");
    Halt();
    /* not reached */
}
