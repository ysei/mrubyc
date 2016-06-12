#
# mruby/c  sample_c/Makefile
#
# Copyright (C) 2015,2016 Kyushu Institute of Technology.
# Copyright (C) 2015,2016 Shimane IT Open-Innovation Center.
#
#  This file is distributed under BSD 3-Clause License.
#

#	furui konpaira





# CPPFLAGS = -g -I ../src
# CPPFLAGS = -g -I../src
CPPFLAGS = -I../src
# LDFLAGS = -L ../src
LDFLAGS = -L../src
LDLIBS = -lmrubyc


CC = gcc
OPTCFLAGS = -Os
# LL = ld
# CFLAGS = -Wall -g # -DDEBUG
# CFLAGS = -Wall -g -v -H -save-temps -S -M -dM $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) # -DDEBUG
# CFLAGS = -Wall -g -v -H -save-temps $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) # -DDEBUG
CFLAGS = -Wall -v -H -save-temps $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) # -DDEBUG

# C_INCLUDE_PATH = $(BEINCLUDES)
# INCLUDES = -I/boot/develop/headers

# CFLAGS += " $(INCLUDES) "
# CC += $(CFLAGS)


all: mrubyc mrubyc_sample mrubyc_concurrent

mrubyc: main.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) main.o $(LDFLAGS) $(LDLIBS) -o $@
# 	$(LL) main.o $(LDFLAGS) $(LDLIBS) -o $@
#	gcc  $@ $^ $(LDFLAGS) $(LDLIBS)

mrubyc_sample: main_sample.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) main_sample.o  $(LDFLAGS) $(LDLIBS) -o $@

mrubyc_concurrent: main_concurrent.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) main_concurrent.o $(LDFLAGS) $(LDLIBS) -o $@

clean:
	@rm -f *.o mrubyc mrubyc_sample mrubyc_concurrent
