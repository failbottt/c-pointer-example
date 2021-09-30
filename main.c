#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const char *stream = "The title of the post\nthe description of the post\n09-09-21\n\nThis is the content of the post\npart of the same paragraph\n\nand this is a new paragraph";

typedef struct post {
    const char *stream;
    const char *title;
    const char *description;
    const char *date;
    const char *content;
} post;

const char*
substr(const char *start, const char *end) 
{
    int len = end - start;
    char *str = malloc(len);
    strncpy(str, start, (end - start));  
    return str;
}

int main() {
    int x = 0; 
    const char *start = stream; 

    post p = {stream, 0, 0, 0, 0, 0};

    while (*stream) {
        if (*stream == '\n' && x < 4) {
            if (x == 0) p.title = substr(start, stream);
            if (x == 1) p.description = substr(start, stream);
            if (x == 2) { 
                p.date = substr(start, stream);
                p.content = ++stream; 
                break;
            };
            
            x++;
            start = ++stream;
        }

        stream++;
    }

    assert(strcmp(p.title, "The title of the post") == 0);
    assert(strcmp(p.description, "the description of the post") == 0);
    assert(strcmp(p.date, "09-09-21") == 0);

    return 0;
}
