#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include "PBEWithMD5AndDES.h"

static void asctohex(unsigned char * asc, size_t size)
{
        size_t i;
        for (i = 0; i < size; i ++)
                printf("%02x", asc[i]);
        printf("\n");
}

int main(void)
{
        unsigned char passwd[] = "jasypt";
        size_t size, passwd_size = strlen((char *)passwd);
        char *encrypt = NULL;
        unsigned char *decrypt = NULL;

#if 0
        unsigned char msg[] = "hello, world\n";
        size_t msg_size = strlen((char *)msg);

#else /* Generate random message for test */

        unsigned char *msg;
        size_t msg_size;

        RAND_bytes((unsigned char *)&msg_size, 4);
        msg_size %= 1024;
        msg_size = (msg_size == 0 ? 1024 : msg_size);
        printf("Encode size: %d\n", (int)msg_size);

        msg = malloc(msg_size);         /* example only, won't free() */
        RAND_bytes(msg, msg_size);
#endif
        asctohex(msg, msg_size);

        printf("\n========================================\n");

        if (PBEWithMD5AndDES_encrypt(msg, msg_size, passwd, passwd_size, &encrypt) != NULL) {
                printf("\n[ Encoded Base64 String ]\n%s\n", encrypt);
        } else {
                printf("PBEWithMD5AndDES_encrypt() returns error.\n");
                return -1;
        }

        printf("\n========================================\n");

        if (PBEWithMD5AndDES_decrypt(encrypt, passwd, passwd_size, &decrypt, &size) != NULL) {
                printf("Decode size: %d\n", (int)size);
                asctohex(decrypt, size);
        } else {
                printf("PBEWithMD5AndDES_encrypt() returns error.\n");
                return -1;
        }

        /* PLEASE REMEMBER TO FREE! */
        free(encrypt);
        free(decrypt);

        return 0;
}

