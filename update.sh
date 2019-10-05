#!/bin/bash
# updates with files from glibc tree
shopt -s extglob

GLIBC=$1

mkdir -p support
mkdir -p string
mkdir -p wcsmbs
mkdir -p sysdeps/generic

cp -a ${GLIBC}/benchtests/!(Makefile) .
cp ${GLIBC}/benchtests/*.c .
cp ${GLIBC}/support/{support_test_main.c,test-driver.c,set_fortify_handler.c,ignore_stderr.c,xpthread_create.c,xpthread_check_return.c,check.c,support_record_failure.c,write_message.c,xpthread_attr_setstacksize.c,xpthread_attr_setguardsize.c,xpthread_join.c,xpthread_attr_init.c,check.h,support.h,temp_file-internal.h,temp_file.h,test-driver.h,xsignal.h,xthread.h} support
cp ${GLIBC}/sysdeps/generic/{_itoa.h,hp-timing-common.h,hp-timing.h,memcopy.h,pagecopy.h} sysdeps/generic
cp ${GLIBC}/string/{memcpy.c,memmove.c,memset.c,str-two-way.h,strcasestr.c,strlen.c,strnlen.c,wordcopy.c} string
cp ${GLIBC}/wcsmbs/{wcslen.c,wcsnlen.c,wmemset.c} wcsmbs

cp ${GLIBC}/include/ifunc-impl-list.h include
cp ${GLIBC}/libof-iterator.mk .
cp ${GLIBC}/test-skeleton.c .
