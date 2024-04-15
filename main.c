#include <unistd.h>

int main(void)
{
    fd = open("texte.txt", O_RDONLY);
    get_next_line(fd);
}