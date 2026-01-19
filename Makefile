#
# Makefile
#
CC ?= gcc
LVGL_DEMO_DIR ?= ${shell pwd}
LVGL_PATH := $(LVGL_DEMO_DIR)/lvgl
CFLAGS := -O0 -g  
CFLAGS += -I$(LVGL_DEMO_DIR)

CFLAGS += -DLV_CONF_INCLUDE_SIMPLE 
CFLAGS += -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function 
CFLAGS += -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized 
CFLAGS += -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral 
CFLAGS += -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers 
CFLAGS += -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body 
CFLAGS += -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers 
CFLAGS += -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess 
CFLAGS += -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar 
CFLAGS += -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare

LDFLAGS ?= -lm 
LDFLAGS += -ldrm -lSDL2 -L/opt/libjpeg-turbo/lib64 -Wl,-Bstatic -lturbojpeg -ljpeg -Wl,-Bdynamic
#-lSDL2 -lavdevice -lavformat -lavcodec -lswscale -lavutil 
BIN = demo.bin


# sudo apt-get install libjpeg-turbo8-dev

#Collect the files to compile

CSRCS += $(shell find $(LVGL_DEMO_DIR)/custom/ -type f -name '*.c')
CSRCS += $(shell find $(LVGL_DEMO_DIR)/generated/ -type f -name '*.c')
CFLAGS += -I$(LVGL_DEMO_DIR)/custom
CFLAGS += -I$(LVGL_DEMO_DIR)/generated

CSRCS += $(shell find $(LVGL_DEMO_DIR)/lvgl/src/ -type f -name '*.c')
CSRCS += $(shell find $(LVGL_DEMO_DIR)/lvgl/demos/ -type f -name '*.c')
CFLAGS += -I$(LVGL_DEMO_DIR)/lvgl
CFLAGS += -I$(LVGL_DEMO_DIR)/lvgl/src

CSRCS += $(shell find $(LVGL_DEMO_DIR)/ports/linux/ -type f -name '*.c')
CFLAGS += -I$(LVGL_DEMO_DIR)/ports/linux

CFLAGS += -I/usr/include/libdrm 
CFLAGS += -I/opt/libjpeg-turbo/include


OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS)
OBJS = $(AOBJS) $(COBJS)

all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC  $<"
    
%.o: %.S
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC  $<"


default: $(AOBJS) $(COBJS) 
	$(CC) -o $(BIN)  $(AOBJS) $(COBJS) $(LDFLAGS)

clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS)
