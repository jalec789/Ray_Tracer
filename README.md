# Setup
```
sudo apt-get install libpng-dev
sudo apt-get install libatlas-base-dev
sudo apt-get install libgsl-dev
sudo apt-get install scons
```

# Build
```
scons
```
# Clean
```
scons -c
```
# Run
### Run test 05: 
```
./ray_tracer -i 05.txt
```
### Compare test 05:
```
./ray_tracer -i 05.txt -s 05.png
```
### Run grading script
```
./grading-script.py .
```
