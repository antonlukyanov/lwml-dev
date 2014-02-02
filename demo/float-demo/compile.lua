require "libsys"

__ = sys.exec

__[[ g++ -o float1-o3.exe -O3 float1.cc ]]
__[[ g++ -o float1-o3-fs.exe -O3 -ffloat-store float1.cc ]]
__[[ g++ -o float1-o3-fm.exe -O3 -ffast-math float1.cc ]]
