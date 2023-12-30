cd src

clang -c fs.c -o ../build/fs.o
clang -c test.c -o ../build/test.o

clang ../build/fs.o ../build/test.o -o ../build/fs

cd ..
cd build

./fs

less fs_data
