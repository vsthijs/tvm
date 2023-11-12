CC := cc
CPPFLAGS := \
	-Iinclude

CFLAGS := -Wall -ggdb -std=c11

LDFLAGS := 
SOURCE := $(shell find src -type f -regex ".*\.c")
OUT := tvm

$(OUT): $(SOURCE)
	$(CC) -o $(OUT) $(CFLAGS) $(CPPFLAGS) $(SOURCE)

test: $(SOURCE)
	@$(CC) -o $(OUT) $(CFLAGS) $(CPPFLAGS) -DTVM_TEST $(SOURCE)
	@./$(OUT)

.PHONY: clean
clean:
	rm -rf $(OUT)