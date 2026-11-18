#include <iostream>
#include "Emitter.h"
#include <sstream>
#include <iomanip>

#include <filesystem>

std::string makeFileName(const std::string &_prefix, int _frame)
{
    std::ostringstream name;
    name << _prefix << '.' << std::setw(4) << std::setfill('0') << _frame << ".geo";
    return name.str();
}

int main()
{
  std::cout << "Writing to: " << std::filesystem::current_path() << '\n';

  Emitter emitter = Emitter(Vec3(0.0f, 1.0f, 0.0f), 100);
  int frame = 0;

  while(frame < 25) {
    const float dt = 1.0f / 24.0f;

    emitter.update(dt);
    emitter.draw(makeFileName("output_", frame));

    ++frame;
  }
  std::cout<<"Particle System\n";
  return EXIT_SUCCESS;
}