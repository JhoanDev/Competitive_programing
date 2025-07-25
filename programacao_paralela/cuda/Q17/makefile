TARGET = main
NVCC = nvcc
FLAGS = -arch=native

all: $(TARGET)

$(TARGET): bitonic_sort.cu
	$(NVCC) $(FLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
