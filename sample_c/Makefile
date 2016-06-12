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
CPPFLAGS = -cwd explicit -I../src -i- -I/boot/home/config/include -I/boot/develop/headers/  -I/boot/develop_x86/headers/ 
# LDFLAGS = -L ../src
# LDFLAGS = -L../src
# LDFLAGS = -l ../src
# LDFLAGS = -l../src
LDFLAGS = -nodefaults -nostdlib -L../src -L/boot/develop/lib/ppc -L/boot/home/config/lib # -lstart_dyn.o -linit_term_dyn.o
# LDFLAGS = -nodefaults -nostdlib -L../src -L/boot/develop/lib/ppc -L/boot/home/config/lib # -lstart_dyn.o
# LDFLAGS = -L/boot/develop/lib/ppc  -L/boot/develop_ppc/lib/ppc # -lstart_dyn.o -linit_term_dyn.o
# LDFLAGS = 

COMMON_OBJ = class.o global.o load.o vm.o static.o value.o common.o symbol.o
RUBY_LIBS = c_array.o c_numeric.o
# OBJ1 := $(patsubst %.c,%.o,$(filter-out $(EXCEPT1),$(wildcard $(BASEDIR)/*.c)))

LDLIBS = -lmrubyc
# LDLIBS = libmrubyc.a
# LDLIBS = $(COMMON_OBJ) $(RUBY_LIBS)

CC = cc
OPTCFLAGS = -Os

# CFLAGS = -Wall -g # -DDEBUG
# CFLAGS = -v $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) # -DDEBUG
CFLAGS = -v $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) # -DDEBUG

# export MWLibraryFiles=glue-noinit.a:init_term_dyn.o:kitruntime_sta.a:libGL.so:libatalk.so:libbae.so:libbe.so:libdevel.a:libdevice.so:libfl.a:libgame.so:libmail.so:libmedia.so:libmidi.so:libmidi2.so:libmp3.so:libmslcpp_4_0.a:libnet.so:libnetapi.so:libnetdev.so:libpng.a:libroot.so:libscreensaver.so:libtermcap.a:libtextencoding.so:libtracker.so    


all: mrubyc mrubyc_sample mrubyc_concurrent

# $(LDLIBS): ../src/$@ # $(COMMON_OBJ) $(RUBY_LIBS)
# 	ln -sv ../src/$@
#	cd ../src && ln -sv $(COMMON_OBJ) $(RUBY_LIBS) ../sample_c/

mrubyc: main.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
#	ln -sv  ../src $(LDLIBS)
#	find ../src/*.o | xargs -n1 ln -sv ; echo -n ''
	$(CC) -v main.o $(LDFLAGS) $(LDLIBS) /boot/develop/lib/ppc/start_dyn.o /boot/develop/lib/ppc/init_term_dyn.o -o $@ -linit_term_dyn.o -lglue-noinit.a -linit_term_dyn.o -lkitruntime_sta.a -llibGL.so -llibatalk.so -llibbae.so -llibbe.so -llibdevel.a -llibdevice.so -llibfl.a -llibgame.so -llibmail.so -llibmedia.so -llibmidi.so -llibmidi2.so -llibmp3.so -llibmslcpp_4_0.a -llibnet.so -llibnetapi.so -llibnetdev.so -llibpng.a -llibroot.so -llibscreensaver.so -llibtermcap.a -llibtextencoding.so -llibtracker.so -llibtranslation.so -llibz.a -lstart_dyn.o
# -noinit -noterm -l$(MWLibraryFiles)
#	$(CC) main.o $(LDFLAGS)/$(LDLIBS) -o $@
#	gcc  $@ $^ $(LDFLAGS) $(LDLIBS)

mrubyc_sample: main_sample.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) main_sample.o  $(LDFLAGS) $(LDLIBS) -o $@

mrubyc_concurrent: main_concurrent.o 
#	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) main_concurrent.o $(LDFLAGS) $(LDLIBS) -o $@

clean:
#	@rm -f *.o mrubyc mrubyc_sample mrubyc_concurrent
	@rm -f *.o *.h mrubyc mrubyc_sample mrubyc_concurrent
