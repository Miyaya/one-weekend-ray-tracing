# one-weekend-ray-tracing
 
## compile and execute

#### 01 print image
```
g++ src/01-print-image.cpp -o build/01-print-image
./build/01-print-image > images/image-01.ppm
```

#### 02 print image using vec3 head file
```
g++ src/02-print-image-vec3.cpp -o build/02-print-image-vec3
./build/02-print-image-vec3 > images/image-02.ppm
```

#### 03 linear interpolation gradient background
```
g++ src/03-ray.cpp -o build/03-ray; ./build/03-ray > images/image-03.ppm
```

#### 04 ray cast with a sphere
```
g++ src/04-sphere.cpp -o build/04-sphere; ./build/04-sphere > images/image-04.ppm
```