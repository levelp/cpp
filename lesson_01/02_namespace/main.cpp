#include <iostream>

// Библиотека для работы с видео
namespace video {
int videoFunction() {};
int counter;
}

// Библиотека для работы со звуком
namespace audio {
int audioFunction() {};
int counter;
}

namespace my_namespace {
int i;
int cout;

namespace inner_namespace {
int b;
}
}

namespace audio {
int secondAudioVar;
}

//using namespace std;
using namespace audio;
using namespace video;

int main() {
  audioFunction();
  videoFunction();

  audio::counter = 10;
  video::counter = 12;

  my_namespace::i = 10;
  my_namespace::inner_namespace::b = 3;
  //  i = 12;
  my_namespace::cout = 15;

  std::cout << "Hello world!" << std::endl;
  return 0;
}
