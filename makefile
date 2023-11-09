CC := cc
CPPFLAGS := \
	-Iinclude

CFLAGS := -Wall -ggdb

LDFLAGS := 

SOURCE := src/**.c
OUT := tvm

$(OUT): $(SOURCE)
	$(CC) -o $(OUT) $(CFLAGS) $(CPPFLAGS) $(SOURCE)

.PHONY: clean
clean:
	rm -rf $(OUT)