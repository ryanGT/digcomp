#ifndef digcomp_h
#define digcomp_h

#include "Arduino.h"


void shift_array(float new_in, float vect_in[], int len_vect);

class dig_comp
{
 public:
  dig_comp(float *b_vect, float *a_vect, float *in_vect, float *out_vect, 
           int len_in, int len_out);
  float calc_out(float new_in);
  int _len_out;
  int _len_in;
  float *_b_vect;
  float *_a_vect;
  float *_in_vect;
  float *_out_vect;
};

class dig_compd
{
public:
  dig_compd(float *b_vect, float *a_vect, int len_in, int len_out);
  float calc_out(float new_in);
  int _len_out;
  int _len_in;
  float *_b_vect;
  float *_a_vect;
  float *_in_vect;
  float *_out_vect;
  //~dig_compd();
};

/*class dig_compv
{
 public:
  dig_compv(float *b_vect, float *a_vect, int len_in, int len_out);
  float calc_out(float new_in);
  int _len_out;
  int _len_in;
  float *_b_vect;
  float *_a_vect;
  //vector<float> _in_vect;
  //vector<float> _out_vect;
  //~dig_compd();
  };*/

#endif
