project adapted from: https://nccastaff.bournemouth.ac.uk/jmacey/cfgaa/labs/lab5/lab5/

cp ~/Downloads/Particle.tgz ./
tar vfxz Particle.tgz
cd Particle
mkdir build
cd build
cmake ..
cmake --build .
