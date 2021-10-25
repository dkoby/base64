/*
 * 2021 Dmitrij Kobilin.
 *
 * Nenia permesilo ekzistas.
 * Faru bone, ne faru malbone.
 */
#ifndef _BASE64_H
#define _BASE64_H

#define BASE64_OUTPUT_SIZE(inSize) ((inSize) * 8 / 6 + (3 + 1))
void base64(char *input, unsigned int inputSize, char *output);

#endif

