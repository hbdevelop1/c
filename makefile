
FLAG2=-Wall -std=c++11
#INCLUDE = -I/usr/include/
#LIBDIR  = -L/usr/lib -L/usr/i686-pc-cygwin/sys-root/usr/lib/
LIBS = -lpthread

compile:
	g++ -ggdb $(FLAG2) $(INCLUDE) $(LIBDIR) exceptions/except01.cpp -o e $(LIBS) 

pp:
	g++ -ggdb $(FLAG2) -E mt_recursive_lock.cpp -o code.i

