# ifndef GNL_H
#define GNL_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *ft_strdup(char *str);
char *gnl(int fd);
#endif