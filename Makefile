CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = Frost_Lea_QuickSort
FILE_TARGET = Frost_Lea_InputFileGenerator

SOURCES = src/Frost_Lea_QuickSort.cpp src/File_Handler.cpp
FILE_SOURCES = src/Frost_Lea_InputFileGenerator.cpp src/File_Handler.cpp

all: $(TARGET) $(FILE_TARGET)

#to run quicksort on one file, run make then ./Frost_Lea_QuickSort <input_file> <output_file>
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

#cleaning up files after running
clean:
	rm -f $(TARGET)
	rm -f $(FILE_TARGET)
	rm -f output/*
	rm -f input/*

#for generating input files, run make generate_files
$(FILE_TARGET): $(FILE_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(FILE_TARGET) $(FILE_SOURCES)

generate_files: $(FILE_TARGET)
	./$(FILE_TARGET)

compute_avg_time: $(TARGET)
	./$(TARGET)

run: 
	make clean
	make generate_files
	make quick_sort
	make compute_avg_time

#quick sort all generated input files
quick_sort: $(TARGET)
	@for i in $(shell seq 1 25); do \
		echo "Processing input/input_10_$$i.txt"; \
		./$(TARGET) input/input_10_$$i.txt output/output_10_$$i.txt; \
	done
	@for i in $(shell seq 1 25); do \
		echo "Processing input/input_100_$$i.txt"; \
		./$(TARGET) input/input_100_$$i.txt output/output_100_$$i.txt; \
	done
	@for i in $(shell seq 1 25); do \
		echo "Processing input/input_1000_$$i.txt"; \
		./$(TARGET) input/input_1000_$$i.txt output/output_1000_$$i.txt; \
	done
