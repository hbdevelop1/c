
FLAG2=-Wall -std=c++14
#INCLUDE = -I/usr/include/
#LIBDIR  = -L/usr/lib -L/usr/i686-pc-cygwin/sys-root/usr/lib/
LIBS = -lpthread

#file=exceptions/except01.cpp
#file=mt_condition_var1.cpp
#file=copy_constructor.cpp
#file=modern.cpp
clientfile=tcpip/client.cpp
serverfile=tcpip/server.cpp
file=algo/arithmeticProgression.cpp
file=class_sizeof.cpp
file=function_pointer.cpp
file=algo/binarySearch.cpp
file=algo/lexical_analyzer.cpp
file=algo/sorting_heapsort.cpp
file=algo/sorting_mergesort.cpp
#file=algo/sorting_quicksort.cpp
#file=task4.cpp
compile:
	g++ -ggdb $(FLAG2) $(INCLUDE) $(LIBDIR) $(file) -o e $(LIBS) 

client:
	g++ -ggdb $(FLAG2) $(INCLUDE) $(LIBDIR) $(clientfile) -o c $(LIBS) 

server:
	g++ -ggdb $(FLAG2) $(INCLUDE) $(LIBDIR) $(serverfile) -o s $(LIBS) 

pp:
	g++ -ggdb $(FLAG2) -E mt_recursive_lock.cpp -o code.i

