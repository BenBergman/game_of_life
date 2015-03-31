all: codeCppUTest

clean: cleanCodeCppUTest

codeCppUTest: CppUTest CppUTestExt
	make -i -f Makefile_CppUTest.mk

cleanCodeCppUTest:
	make -i -f Makefile_CppUTest.mk clean

CppUTest: CppUTest/lib CppUTest/lib/libCppUTest.a

CppUTest/lib/libCppUTest.a:
	make -i -C CppUTest/cpputest_build

CppUTestExt: CppUTest/cpputest_build/lib/libCppUTestExt.a

CppUTest/cpputest_build/lib/libCppUTestExt.a:
	make -i -C CppUTest extensions

CppUTest/lib:
	ln -s $(shell pwd)/CppUTest/cpputest_build/lib CppUTest/lib
