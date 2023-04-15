
CURRENT=$(cd $(dirname $0);pwd)

build_dir="build_dir"
run_exe="example/main"

cmake -B $build_dir
cd $build_dir
make
./$run_exe

cd $CURRENT