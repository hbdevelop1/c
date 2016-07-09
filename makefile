#INCLUDE = -I/usr/include/
#LIBDIR  = -L/usr/lib -L/usr/i686-pc-cygwin/sys-root/usr/lib/
LIBS = -lpthread

#file=exceptions/except01.cpp
#file=mt_condition_var1.cpp
#file=copy_constructor.cpp

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
file=mem_get_temporary_buffer.cpp
file=stl_copy.cpp
file=p1/template19.cpp
file=code2.cpp
file=p1/hackerrank_Staircase.cpp
file=mt_future.cpp
file=mt_future_exception.cpp
file=optim_pack.cpp
file=task3.cpp
file=algo/wg_visible_nodes.cpp
file=optim_memcpy.cpp
file=3d/vec3_test.cpp
file=3d/plane_test.cpp
file=test_gl_compress.cpp
file=embedded/bits.cpp
file=algo/number_palindrome.cpp
file=overflow.cpp
file=algo/wg_anagrampalindrome.cpp
file=algo/sorting_quicksort2.cpp
file=embedded/const.cpp
file=p1/isDerivedFrom.cpp
file=modern_copy01.cpp

file=embedded/function_pointer.c
file=embedded/array.c
file=class_overloading.cpp
file=class_pointer_member.cpp
file=tst_factorial.cpp
file=tst_memcpy.cpp
file=stl_hash.cpp
file=tst_graph.cpp
file=stl_multiset.cpp
file=embedded/swap_bits.cpp
file=algo/reverse_list.cpp
file=modern_template_variadic.cpp
file=mt/mt_writerReaders.cpp
file=modern_rvalue.cpp
file=modern_lambda.cpp
file=3d/line_point.cpp 3d/vec3.cpp
file=modern_for_range2.cpp
file=stl_iterator1.cpp
file=template_types.cpp
file=template_specialization01.cpp
file=template_different_retrunTypes.cpp
file=template_friend.cpp
file=exceptions/throw01.cpp
file=stl_vector_erase.cpp
file=class_pointer_member.cpp
file =class_inheritance.cpp
file=stl_iterator2.cpp
file=embedded/endians.cpp
file=asm_function_call.cpp
file=algo/arithmeticProgression_getStep.cpp
file=class_inheritance_array.cpp
file=modern_shared.cpp
file=class_final.cpp
file=inheritance_private.cpp
file=mem_newOverloaded.cpp
#file=modern.cpp
file=modern_for_range2.cpp
file=modern_move01.cpp
file=exercises.cpp

clientfile=mt_ATM/ATMClient.cpp
serverfile=mt_ATM/ATMServer.cpp


COMPILER=g++
FLAG2=-Wall -std=c++14

compile:
	$(COMPILER) -ggdb3 $(FLAG2) $(INCLUDE) $(LIBDIR) $(file) -o e $(LIBS)

client:
	g++ -ggdb3 $(FLAG2) $(INCLUDE) $(LIBDIR) $(clientfile) -o c $(LIBS) 

server:
	g++ -ggdb3 $(FLAG2) $(INCLUDE) $(LIBDIR) $(serverfile) -o s $(LIBS) 

pp:
	g++ -ggdb3 $(FLAG2) $(INCLUDE) $(LIBDIR) -E $(file) -o code.i

