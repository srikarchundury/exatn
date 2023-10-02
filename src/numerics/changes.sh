rm -rf CMakeFiles CMakeCache.txt
 
CC=gcc CXX=g++ FC=gfortran cmake . -DCMAKE_INSTALL_PREFIX=${EXATN_INSTALL_PATH} -DEXATN_BUILD_TESTS=TRUE -DBLAS_LIB=OPENBLAS -DBLAS_PATH=${OPEN_BLAS_PATH} -DWITH_LAPACK=YES

cd ../../../../exatn/build/src/numerics/

make install

# cd /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/numerics/tests

# ./NumericsTester
