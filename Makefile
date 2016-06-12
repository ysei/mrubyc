#
# mruby/c  Makefile
#
# Copyright (C) 2015,2016 Kyushu Institute of Technology.
# Copyright (C) 2015,2016 Shimane IT Open-Innovation Center.
#
#  This file is distributed under BSD 3-Clause License.
#


#	furui konpaira




CC = cc
OPTCFLAGS = -Os

# CFLAGS = -Wall -g # -DDEBUG
# CFLAGS = -Wall -g -v -H -save-temps -S -M -dM $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) # -DDEBUG
# CFLAGS = -Wall -g -v -H -save-temps $(DEFAULTCFLAGS) $(FUNCCFLAGS) $(OPTCFLAGS) # -DDEBUG
CFLAGS = -Os -cwd explicit -I./ -i- -I/boot/home/config/include -I/boot/develop/headers/  -I/boot/develop_x86/headers/ # -I./ # 



all: mrubyc_lib mrubyc_bin


mrubyc_lib:
	cd src ; make all

mrubyc_bin:
	cd sample_c ; make all

clean:
	cd src ; make clean
	cd sample_c ; make clean

package: clean
	@LANG=C ;\
	TARGET="mruby-c_`head -n1 Version`" ;\
	if [ -n "$$MRUBYC_VERSION" ] ;\
		then TARGET="mruby-c_$$MRUBYC_VERSION" ;\
	fi ;\
	echo Making \"$$TARGET.tgz\" ;\
	mkdir -p pkg/$$TARGET ;\
	cp -Rp src doc sample_c sample_ruby auto_test README.md Makefile pkg/$$TARGET ;\
	cd pkg ;\
	tar cfz ../$$TARGET.tgz $$TARGET ;\
	cd .. ;\
	rm -Rf pkg ;\
	echo Done.
