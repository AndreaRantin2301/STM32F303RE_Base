Compiler=arm-none-eabi-gcc
Core=cortex-m4
CFlags = -c -mcpu=cortex-m4 -Iinc -Ithird_party -mthumb -std=gnu23 -mfloat-abi=soft -g -O0 \
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
SRC_DIR = src
CLOCK_DRIVER_DIR = $(SRC_DIR)/clock_driver
GPIO_DRIVER_DIR = $(SRC_DIR)/gpio_driver
USART_DRIVER_DIR = $(SRC_DIR)/usart_driver
UTILS_DIR = $(SRC_DIR)/utils

$(STARTUP_DIR):
	mkdir $@

$(OUT_DIR):
	mkdir $@

$(DEBUG_DIR):
	mkdir $@

all: $(OUT_DIR) main.o startup.o clock_driver.o gpio_driver.o usart_driver.o string_utils.o $(DEBUG_DIR)/firmware.elf

main.o:main.c | $(OUT_DIR)
	$(Compiler) $(CFlags) main.c -o $(OUT_DIR)/main.o

startup.o:$(STARTUP_DIR)/startup.s | $(OUT_DIR)
	$(Compiler) $(CFlags) $(STARTUP_DIR)/startup.s -o $(OUT_DIR)/startup.o

clock_driver.o:$(CLOCK_DRIVER_DIR)/clock_driver.c | $(OUT_DIR)
	$(Compiler) $(CFlags) $(CLOCK_DRIVER_DIR)/clock_driver.c -o $(OUT_DIR)/clock_driver.o

gpio_driver.o:$(GPIO_DRIVER_DIR)/gpio_driver.c | $(OUT_DIR)
	$(Compiler) $(CFlags) $(GPIO_DRIVER_DIR)/gpio_driver.c -o $(OUT_DIR)/gpio_driver.o

usart_driver.o:$(USART_DRIVER_DIR)/usart_driver.c | $(OUT_DIR)
	$(Compiler) $(CFlags) $(USART_DRIVER_DIR)/usart_driver.c -o $(OUT_DIR)/usart_driver.o

string_utils.o:$(UTILS_DIR)/string_utils.c | $(OUT_DIR)
	$(Compiler) $(CFlags) $(UTILS_DIR)/string_utils.c -o $(OUT_DIR)/string_utils.o

$(DEBUG_DIR)/firmware.elf: $(OUT_DIR)/main.o $(OUT_DIR)/startup.o $(OUT_DIR)/clock_driver.o $(OUT_DIR)/gpio_driver.o $(OUT_DIR)/usart_driver.o $(OUT_DIR)/string_utils.o | $(DEBUG_DIR)
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