TARGET = main
NVCC = nvcc
FLAGS = -arch=native

all: $(TARGET)

$(TARGET): matriz.cu
	$(NVCC) $(FLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
