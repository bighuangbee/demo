#g++ simple.cpp -fPIC -shared -o libExample.so
g++ -g -o libExample.so -shared -fPIC -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H simple.cpp