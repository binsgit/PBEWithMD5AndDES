#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include "PBEWithMD5AndDES.h"

static int usage(char * cmd)
{
        fprintf(stderr, "\nUSAGE: %s input=<input> password=<password>\n\n", cmd);
        return (-1);
}

int main(int argc, char *argv[])
{
        char *input = NULL;
        char *password = NULL;
        char *encrypt;
        size_t i;

        if (argc != 3) {
                return usage(argv[0]);
        }

        for (i = 1; i < 3; i ++) {
                if (!strncmp(argv[i], "input=", strlen("input="))) {
                        input = &(argv[i][strlen("input=")]);
                }
                if (!strncmp(argv[i], "password=", strlen("password="))) {
                        password = &(argv[i][strlen("password=")]);
                }
        }

        if ((input == NULL) || (password == NULL)) {
                return usage(argv[0]);
        }

        printf("\n----ARGUMENTS-------------------\n\n");
        printf("input: %s\npassword: %s\n\n\n", input, password);

        if (PBEWithMD5AndDES_encrypt((unsigned char *)input, strlen(input), (unsigned char *)password, strlen(password), &encrypt) != NULL) {
                printf("\n----OUTPUT----------------------\n\n");
                printf("%s\n\n\n", encrypt);
        } else {
                printf("PBEWithMD5AndDES_encrypt() returns error.\n");
                return -1;
        }

        /* PLEASE REMEMBER TO FREE! */
        free(encrypt);

        return 0;
}

