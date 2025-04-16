Compiler=arm-none-eabi-gcc
Core=cortex-m4
CFlags = -c -mcpu=cortex-m4 -mthumb -std=gnu23 -mfloat-abi=soft -g -O0 \
		 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wpointer-arith -Wcast-qual \
		 -Wcast-align -Wsign-conversion -Wswitch-default -Wswitch-enum \
		 -Wstrict-prototypes -Wmissing-prototypes -Wconversion -Wredundant-decls \
		 -Winline -Wundef -Wbad-function-cast -Wfloat-equal -Wlogical-op \
		 -Waggregate-return -Wformat=2 -Wmissing-include-dirs -Wstrict-overflow=5 \
		 -Wunreachable-code -Wunused -Wuninitialized -Wnull-dereference \
		 -Wduplicated-cond -Wno-unused-parameter -pedantic-errors \
		 -Wvla -Wnonnull -Wmisleading-indentation -Wpointer-arith \
		 -Wcast-align -Wlogical-op -Waggregate-return -Wfloat-equal \
		 -Wpacked -Wno-inline

LDFlags= -mcpu=$(Core) -mthumb -nostdlib -T $(STARTUP_DIR)/linkerScript.ld -Wl,-Map=$(DEBUG_DIR)/firmware.map

STARTUP_DIR = startup
OUT_DIR	=	out
DEBUG_DIR =	debug

$(STARTUP_DIR):
	mkdir $@

$(OUT_DIR):
	mkdir $@

$(DEBUG_DIR):
	mkdir $@

all: $(OUT_DIR) main.o startup.o $(DEBUG_DIR)/firmware.elf

main.o:main.c | $(OUT_DIR)
	$(Compiler) $(CFlags) main.c -o $(OUT_DIR)/main.o

startup.o:$(STARTUP_DIR)/startup.s | $(OUT_DIR)
	$(Compiler) $(CFlags) $(STARTUP_DIR)/startup.s -o $(OUT_DIR)/startup.o

$(DEBUG_DIR)/firmware.elf: $(OUT_DIR)/main.o $(OUT_DIR)/startup.o | $(DEBUG_DIR)
	$(Compiler) $(LDFlags) -o $@ $^
	arm-none-eabi-objcopy -O binary $(DEBUG_DIR)/firmware.elf $(DEBUG_DIR)/firmware.bin

clean:
	rmdir /S /Q $(DOCS_DIR)\html 2>nul || exit 0
	rmdir /S /Q $(DOCS_DIR)\latex 2>nul || exit 0
	rmdir /S /Q $(DEBUG_DIR) 2>nul || exit 0
	rmdir /S /Q $(OUT_DIR) 2>nul || exit 0
	del /Q *.o *.elf *.map 2>nul || exit 0

size:
	arm-none-eabi-size $(DEBUG_DIR)/firmware.elf