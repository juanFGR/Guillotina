CC=gcc
CXX=g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)

RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2
LINKFLAGS= -lcppunit

FRAMEWORK_SRS=../cortes.cc 

SRCS=UnitTestCase.cpp $(FRAMEWORK_SRS) $(EXAMPLE_SRS) $(EXAMPLE_SRS1) $(EXAMPLE_SRS2) $(EXAMPLE_SRS3)
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
