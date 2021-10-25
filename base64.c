/*
 * 2021 Dmitrij Kobilin.
 *
 * Nenia permesilo ekzistas.
 * Faru bone, ne faru malbone.
 */
#include "base64.h"

static const char base64Map[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

/*
 *
 */
void base64(char *input, unsigned int inputSize, char *output)
{
    char tail;

    while (inputSize)
    {
        *output++ = base64Map[*input >> 2];
        tail = *input & 0x03;
        inputSize--;
        if (inputSize == 0)
        {
            *output++ = base64Map[tail << 4];
            *output++ = '=';
            *output++ = '=';
            *output++ = 0;
            break;
        }
        input++;
        *output++ = base64Map[(*input >> 4) | (tail << 4)];
        tail = *input & 0x0f;
        inputSize--;
        if (inputSize == 0)
        {
            *output++ = base64Map[tail << 2];
            *output++ = '=';
            *output++ = 0;
            break;
        }
        input++;
        *output++ = base64Map[(*input >> 6) | (tail << 2)];
        *output++ = base64Map[*input & 0x3F];
        input++;
        inputSize--;
    }
    *output++ = 0;
}

