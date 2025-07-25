TARGET = main
NVCC = nvcc
FLAGS = -arch=native

all: $(TARGET)

$(TARGET): trap_integral.cu
	$(NVCC) $(FLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
