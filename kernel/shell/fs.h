//
// Created by ilu on 6/13/26.
//

#ifndef CODPROJECTS_FS_H
#define CODPROJECTS_FS_H

#define FILES_COUNT 2

struct file {
    const char *name;
    const char *content;
};

extern struct file files[];
#endif //CODPROJECTS_FS_H
