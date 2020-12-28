#g++ simple.cpp -fPIC -shared -o libsimple.so
g++ -g -o ../libsimple.so -shared -fPIC -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H simple.cpp