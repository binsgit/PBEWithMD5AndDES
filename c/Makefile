CC = $(CROSS)gcc
CFLAGS += -W -Wall
#CFLAGS += -DPBEWithMD5AndDES_DEBUG
LDFLAGS += -lssl -lcrypto

all: example encrypt decrypt

example: example.c PBEWithMD5AndDES.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

encrypt: encrypt.c PBEWithMD5AndDES.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

decrypt: decrypt.c PBEWithMD5AndDES.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *.exe example encrypt decrypt

