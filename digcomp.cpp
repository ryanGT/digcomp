#include "Arduino.h"
#include "digcomp.h"

#define MAXLEN 10
//using namespace std;

// <iostream> declares cout/cerr, but the application must define them
// because it's up to you what to do with them.

void shift_array(float new_in, float vect_in[], int len_vect){
  int i;
  for(i=len_vect-1; i > 0;i--){
    vect_in[i]=vect_in[i - 1]; // copy
  }
  vect_in[0] = new_in;
}


/*void shift_vector(float new_in, vector<float> &vect_in, int len_vect){
  int i;
  for(i=len_vect-1; i > 0;i--){
    vect_in[i]=vect_in[i - 1]; // copy
  }
  vect_in[0] = new_in;
  }*/


//void do_something(int el, std::vector<int> &arr){
//  arr.insert(arr.begin(), el);
//}

dig_comp::dig_comp(float *b_vect, float *a_vect, 
                   float *in_vect, float *out_vect, 
                   int len_in, int len_out){
  _b_vect = b_vect;
  _a_vect = a_vect;
  _in_vect = in_vect;
  _out_vect = out_vect;
  _len_in = len_in;
  _len_out = len_out;
  int i;
  for(i=0; i < len_in; i++){
    _in_vect[i] = 0;
  }
  for(i=0; i < len_out; i++){
    _out_vect[i] = 0;
  }
}


float dig_comp::calc_out(float new_in){
    float new_out = 0.0;
    shift_array(new_in, _in_vect, _len_in);
    int i;
    for(i=0; i<_len_in; i++){
      new_out += _in_vect[i]*_b_vect[i];
    }
    for(i=1; i<_len_out; i++){
      new_out -= _out_vect[i-1]*_a_vect[i];//out_vect hasn't been shifted yet, so the indices are off by 1
    }
    shift_array(new_out, _out_vect, _len_out);
    return new_out;
}

dig_compd::dig_compd(float *b_vect, float *a_vect, 
                     int len_in, int len_out){
    _b_vect = b_vect;
    _a_vect = a_vect;
    //float* _in_vect;
    //float* _out_vect;
    //_in_vect = new float[len_in];
    //_out_vect = new float[len_out];
    float in_vect[10];
    float out_vect[10];
    _in_vect = in_vect;
    _out_vect = out_vect;
    _len_in = len_in;
    _len_out = len_out;
    int i;
    for(i=0; i < len_in; i++){
      _in_vect[i] = 0;
    }
    for(i=0; i < len_out; i++){
      _out_vect[i] = 0;
    }
}


float dig_compd::calc_out(float new_in){
    float new_out = 0.0;
    shift_array(new_in, _in_vect, _len_in);
    int i;
    for(i=0; i<_len_in; i++){
      new_out += _in_vect[i]*_b_vect[i];
    }
    for(i=1; i<_len_out; i++){
      new_out -= _out_vect[i-1]*_a_vect[i];//out_vect hasn't been shifted yet, so the indices are off by 1
    }
    shift_array(new_out, _out_vect, _len_out);
    return new_out;
}

/*
dig_compd::~dig_compd(){
  delete _in_vect;
  delete [] _in_vect;
  delete _out_vect;
  delete [] _out_vect;
}
*/

/*
dig_compv::dig_compv(float *b_vect, float *a_vect, 
                     int len_in, int len_out){
  _b_vect = b_vect;
  _a_vect = a_vect;
  float* _in_vect;
  float* _out_vect;
  _len_in = len_in;
  _len_out = len_out;
  vector<float> _in_vect(_len_in,0.0);
  vector<float> _out_vect(_len_out,0.0);
  int i;
  for(i=0; i < len_in; i++){
    _in_vect[i] = 0;
  }
  for(i=0; i < len_out; i++){
    _out_vect[i] = 0;
  }
}

float dig_compv::calc_out(float new_in){
  float new_out = 0.0;
  shift_vector(new_in, &_in_vect, _len_in);
  int i;
  for(i=0; i<_len_in; i++){
    new_out += _in_vect[i]*_b_vect[i];
  }
  for(i=1; i<_len_out; i++){
    new_out -= _out_vect[i-1]*_a_vect[i];//out_vect hasn't been shifted yet, so the indices are off by 1
  }
  shift_vector(new_out, &_out_vect, _len_out);
  return new_out;
}

*/
