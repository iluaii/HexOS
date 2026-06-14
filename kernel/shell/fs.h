//
// Created by ilu on 6/13/26.
//

#ifndef CODPROJECTS_FS_H
#define CODPROJECTS_FS_H

struct file {
    char *name;
    char *content;
};

static struct file files[] = {
    {"readme.txt", "welcome to HexOS\n"},
    {"hello.txt",  "hello world\n"},
};

#define FILES_COUNT (sizeof(files) / sizeof(files[0]))

extern struct file files[];
#endif //CODPROJECTS_FS_H
