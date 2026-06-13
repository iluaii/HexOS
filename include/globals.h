#include <stdint.h>

#ifndef CODPROJECTS_GLOBALS_H
#define CODPROJECTS_GLOBALS_H
extern char nameOS[32];
extern char nameUser[64];
extern char versionOS[64];
extern struct multiboot_info *g_mbi;
struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
};
#endif //CODPROJECTS_GLOBALS_H
