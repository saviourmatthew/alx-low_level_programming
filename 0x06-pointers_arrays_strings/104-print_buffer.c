#include <stdio.h>
#include <ctype.h>

void print_buffer(char *b, int size);

/**
 * Prints the content of a buffer in a specific format.
 *
 * @param b The buffer to print.
 * @param size The number of bytes to print from the buffer.
 */
void print_buffer(char *b, int size)
{
    if (size <= 0)
    {
        printf("\n");
        return;
    }

    int bytes_per_line = 10;

    for (int i = 0; i < size; i += bytes_per_line)
    {
        printf("%08x ", i);

        /* Print hexadecimal content */
        for (int j = i; j < i + bytes_per_line; j += 2)
        {
            if (j < size)
            {
                printf("%02x", b[j]);

                if (j + 1 < size)
                {
                    printf("%02x", b[j + 1]);
                }
                else
                {
                    printf("  ");
                }

                printf(" ");
            }
            else
            {
                printf("     ");
            }
        }

        printf(" ");

        /* Print ASCII content */
        for (int j = i; j < i + bytes_per_line; j++)
        {
            if (j < size)
            {
                if (isprint(b[j]))
                {
                    printf("%c", b[j]);
                }
                else
                {
                    printf(".");
                }
            }
            else
            {
                break;
            }
        }

        printf("\n");
    }
}

int main(void)
{
    char buffer[] = {0xde, 0xad, 0xbe, 0xef, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64};
    int size = sizeof(buffer);

    print_buffer(buffer, size);

    return 0;
}

