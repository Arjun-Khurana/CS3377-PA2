VERSION := 1.0
INCREMENT := 0.1

all: filecnt filedisp version
	

filecnt: filecnt.c
	gcc filecnt.c -o filecnt

filedisp: filedisp.c
	gcc filedisp.c -o filedisp

version:
	@./version
	
clean:
	rm -f filecnt
	rm -f filedisp

.PHONY: version