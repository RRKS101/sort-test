Build with C++20 in MSVC.
All tests sort an array with a length of 1024 elements.

`Debug`, `x[i] = rand() % (max+min) + min`
```
List Generator: 204.400000 us
Generated unsorted array of length 1024
  [INFO] Swiftie aux. array with size of 1044
Switfie Sort: 900.300000 us
Swiftie Sort Succeeded
Insertion Sort: 3632.300000 us
Insertion Sort Succeeded
Both sorts worked.
```

`Release+AVX2+FPfast`, `x[i] = rand() % (max+min) + min`
```
List Generator: 101.300000 us
Generated unsorted array of length 1024
  [INFO] Swiftie aux. array with size of 1046
Switfie Sort: 79.100000 us
Swiftie Sort Succeeded
Insertion Sort: 130.800000 us
Insertion Sort Succeeded
Both sorts worked.
```


`Debug`, `x[i] = m * i + b + rand() % (max+min) + min`
```
List Generator: 340.300000 us
Generated unsorted array of length 1024
  [INFO] Swiftie aux. array with size of 1984
Switfie Sort: 553.800000 us
Swiftie Sort Succeeded
Insertion Sort: 3174.400000 us
Insertion Sort Succeeded
Both sorts worked.
```

`Release+AVX2+FPfast`, `x[i] = m * i + b + rand() % (max+min) + min`
```
List Generator: 84.200000 us
Generated unsorted array of length 1024
  [INFO] Swiftie aux. array with size of 2003
Switfie Sort: 103.000000 us
Swiftie Sort Succeeded
Insertion Sort: 170.800000 us
Insertion Sort Succeeded
Both sorts worked.
```
