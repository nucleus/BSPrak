C_SRC         = main.c $(shell find -name '*.c')
ASM_SRC       = $(shell find -name '*.S')
OBJ           = $(C_SRC:%.c=%.o) $(ASM_SRC:%.S=%o)
SRC           = $(C_SRC) $(ASM_SRC)
CC            = arm-elf-gcc
CFLAGS        = -I. -Wall -Werror -fno-builtin -pipe -mcpu=arm920t -O0 -frename-registers -Wno-strict-aliasing -ffunction-sections
LD            = arm-elf-ld
LDFLAGS       = --gc-sections --print-gc-sections
LSCRIPT       = link_portux.ld
OBJCOPY       = arm-elf-objcopy
MKIMAGE       = mkimage
MKIMAGE_FLAGS = -A arm -O netbsd -T standalone -C none -a 0x20000000 -e 0x20000000
IMAGE         = kernel
BOOTIMAGE     = system.img
DEPENDFILE    = depend

all:	$(BOOTIMAGE)

.PHONY: clean dep

clean:
	rm -f $(OBJ) *~ $(IMAGE) $(IMAGE).bin $(BOOTIMAGE)

dep: $(SRC)
	$(CC) $(CFLAGS) -MM $(SRC) > $(DEPENDFILE)

-include $(DEPENDFILE)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.S
	$(CC) $(CFLAGS) -o $@ -c -x assembler $<

$(IMAGE): $(OBJ) $(LSCRIPT)
	$(LD) $(LDFLAGS) -T$(LSCRIPT) -o $@ $^
	$(OBJCOPY) $@ -Obinary $@.bin

$(BOOTIMAGE): $(IMAGE)
	$(MKIMAGE) $(MKIMAGE_FLAGS) -d $(IMAGE).bin $@

install: $(BOOTIMAGE)
	arm-install-image $(BOOTIMAGE)
