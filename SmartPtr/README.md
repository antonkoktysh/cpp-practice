# Shared Pointer

Простая реализация умного указателя `shared_ptr` на C++ для учебных целей.  
Проект демонстрирует принципы подсчёта ссылок, автоматического управления памятью и базовые шаблоны проектирования в C++.  
Цель — разобраться и понять, как работают умные указатели из стандартной библиотеки, пощупать RAII, type erasure.


## Build and Run

### Standard Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
./tests
```

### ASAN Build

```bash
mkdir build-asan && cd build-asan
export ASAN_OPTIONS=detect_leaks=1
cmake -DCMAKE_BUILD_TYPE=ASAN ..
cmake --build .
./tests
```
