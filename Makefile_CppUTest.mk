COMPONENT_NAME = game_of_life

SILENCE = @

CPPUTEST_HOME = CppUTest
#CPPFLAGS += -I$(CPPUTEST_HOME)/include
#CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
#CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
#LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

SRC_DIRS = \
		   src \

TEST_SRC_DIRS = \
				test \

INCLUDE_DIRS = \
			   ./ \
			   $(CPPUTEST_HOME)/include \
			   include \

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
