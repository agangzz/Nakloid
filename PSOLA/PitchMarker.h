#ifndef PitchMarker_h
#define PitchMarker_h

#include <list>
#include <cmath>
#include <vector>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
 
#include "fftw3.h"
#include "../Utilities.h"
#include "../parser/WavData.h"

// Refference Object
class PitchMarker {
 public:
  PitchMarker();
  virtual ~PitchMarker();

  bool mark(std::vector<double> vowel_wav);
  bool mark(std::vector<double> fore_vowel_wav, std::vector<double> aft_vowel_wav);
  bool mark(double hz, unsigned long fs);

  template <class Iterator>
  std::vector<Iterator> mark(Iterator it_vowel_begin, Iterator it_vowel_end,
                             Iterator it_target_begin, Iterator it_target_end,
                             Iterator it_wav_end, bool autocorrelation);

  // accessor
  void setInputWav(std::vector<double>input_wav);
  void setInputWav(std::vector<double>input_wav, short ms_offs, short ms_ovrl, short ms_prec, short ms_blnk, unsigned long fs);
  std::vector<long> getPitchMarks();

 private:
  PitchMarker(const PitchMarker& other);
  PitchMarker& operator=(const PitchMarker& other);

  std::vector<double> xcorr(std::vector<double>::iterator it_target, bool reverse);

  template <class Iterator>
  void xcorr(Iterator it_vowel_begin, Iterator it_vowel_end,
             Iterator it_target_begin, std::vector<double>::iterator it_output);

  std::vector<double> input_wav;
  long pos_offs;
  std::vector<double>::iterator it_input_wav_offs;
  std::vector<double>::iterator it_input_wav_ovrl;
  std::vector<double>::iterator it_input_wav_prec;
  std::vector<double>::iterator it_input_wav_blnk;
  std::vector<long> pitchmarks;
};

#endif

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
