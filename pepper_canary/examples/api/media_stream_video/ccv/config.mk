CC := /home/gu/nacl_sdk/pepper_canary/toolchain/linux_x86_newlib/bin/x86_64-nacl-gcc
AR := /home/gu/nacl_sdk/pepper_canary/toolchain/linux_x86_newlib/bin/x86_64-nacl-ar
NVCC := 
CUDA_OBJS := 
DEFINE_MACROS := -D HAVE_SSE2
CFLAGS := -msse2 $(DEFINE_MACROS)
NVFLAGS := --use_fast_math -arch=sm_30 $(DEFINE_MACROS)
LDFLAGS := -lm
