NVCC = /usr/local/cuda-9.0/bin/nvcc
exec = matrix_mul
debug: $(exec).cu
	$(NVCC) -E $^ -o preprocess
all: $(exec)
$(exec): $(exec).cu $(exec).h
	$(NVCC) -o $@ $<
.PHONY: clean
clean: 
	rm -rf matrix_mul preprocess
