%: %.cu
	nvcc -g -G -o $@ $<
	@mv $@ bin

.PHONY: clean
clean:
	rm -rf bin/*
