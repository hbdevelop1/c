
FLAG2=-Wall -std=c++14
#INCLUDE = -I/usr/include/
#LIBDIR  = -L/usr/lib -L/usr/i686-pc-cygwin/sys-root/usr/lib/
LIBS = -lpthread

file=exceptions/except01.cpp
#file=mt_condition_var1.cpp
#file=copy_constructor.cpp

compile:
	g++ -ggdb $(FLAG2) $(INCLUDE) $(LIBDIR) $(file) -o e $(LIBS) 

pp:
	g++ -ggdb $(FLAG2) -E mt_recursive_lock.cpp -o code.i

