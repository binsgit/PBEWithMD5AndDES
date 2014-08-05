PBEWithMD5AndDES in C and Python
================

##### C &amp; Python 2.x implementation of PBEWithMD5AndDES by Jasypt Java Package: org.jasypt.encryption.pbe.StandardPBEStringEncryptor
----

PBEWithMD5AndDES seems popular in the Java world, and many are asking for implementation of XX language.

The C implementation uses OpenSSL. And I've updated the [Python one on stackoverflow] [1].

Version
----

0.1

C Example Usage
-----------

```sh
$ make
$ ./example
$ ./encrypt input=<your input string> password=<your password string>
$ ./decrypt input=<your input string> password=<your password string>
```

C Example Test
--------------

##### Suppose that your jasypt is extracted into ${JASYPT_PATH}

```sh
$ ${JASYPT_PAHT}/bin/encrypt.sh input=org.jasypt.encryption.pbe.StandardPBEStringEncryptor password=jasypt

----ENVIRONMENT-----------------

Runtime: Sun Microsystems Inc. Java HotSpot(TM) Server VM 20.1-b02



----ARGUMENTS-------------------

input: org.jasypt.encryption.pbe.StandardPBEStringEncryptor
password: jasypt



----OUTPUT----------------------

OyKMSNRI+9UvzG2PtDkYZUgoMIZa+gI6roqTdNY19dqBRGeM+UvnhBodYHZvG8XKZ5JMfEnI43r9jNaeH2wlrg==


$ ./decrypt input="OyKMSNRI+9UvzG2PtDkYZUgoMIZa+gI6roqTdNY19dqBRGeM+UvnhBodYHZvG8XKZ5JMfEnI43r9jNaeH2wlrg==" password=jasypt

----ARGUMENTS-------------------

input: OyKMSNRI+9UvzG2PtDkYZUgoMIZa+gI6roqTdNY19dqBRGeM+UvnhBodYHZvG8XKZ5JMfEnI43r9jNaeH2wlrg==
password: jasypt



----OUTPUT----------------------

org.jasypt.encryption.pbe.StandardPBEStringEncryptor


$ ./encrypt input=org.jasypt.encryption.pbe.StandardPBEStringEncryptor password=jasypt

----ARGUMENTS-------------------

input: org.jasypt.encryption.pbe.StandardPBEStringEncryptor
password: jasypt



----OUTPUT----------------------

5F09DiqsF3B3gFGhcrVlYxHga7PohvZhYnmUIZ/E9u0XXuTgbjyDMTzKkOweTNEmP9zk3EKD1p/oNwzgfINgTg==


$ ${JASYPT_PAHT}/bin/decrypt.sh input="5F09DiqsF3B3gFGhcrVlYxHga7PohvZhYnmUIZ/E9u0XXuTgbjyDMTzKkOweTNEmP9zk3EKD1p/oNwzgfINgTg==" password=jasypt

----ENVIRONMENT-----------------

Runtime: Sun Microsystems Inc. Java HotSpot(TM) Server VM 20.1-b02



----ARGUMENTS-------------------

input: 5F09DiqsF3B3gFGhcrVlYxHga7PohvZhYnmUIZ/E9u0XXuTgbjyDMTzKkOweTNEmP9zk3EKD1p/oNwzgfINgTg==
password: jasypt



----OUTPUT----------------------

org.jasypt.encryption.pbe.StandardPBEStringEncryptor

```

License
----

MIT for C implementation

[Creative Commons] [2] for Python 2.x implementation


[1]:http://stackoverflow.com/questions/10814071/implementation-of-pbewithmd5anddes-in-ruby/25033895
[2]:http://meta.stackexchange.com/questions/12527/do-i-have-to-worry-about-copyright-issues-for-code-posted-on-stack-overflow

