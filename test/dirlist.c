#define ZPL_IMPLEMENTATION
#include <zpl.h>
#include <string.h>

int main()
{
    zpl_string_t files;
    files = zpl_path_dirlist(zpl_heap_allocator(), "/home/zaklaus/dev/zpl", true);

    char *p=strtok(files, "\n");
    while (p) {
        printf("%s\n", p);
        p=strtok(NULL, "\n");
    }

    zpl_string_free(files);

    return 0;
}
