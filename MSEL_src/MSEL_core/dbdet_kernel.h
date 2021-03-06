// This is brcv/seg/dbdet/edge/dbdet_kernel.h
#ifndef dbdet_kernel_h
#define dbdet_kernel_h
//:
//\file
//\brief A base class for 2d convolution kernels that can be shifted
//\author Amir Tamrakar
//\date 09/09/06
//
//\verbatim
//  Modifications
//\endverbatim

#include <vil/vil_image_view.h>

//: base class for shiftable 2d kernels
class dbdet_kernel : public vil_image_view<double>
{
protected:
  double dx, dy; ///< operator shifts,  
  double theta;  ///< operator rotation 

public:
  dbdet_kernel(unsigned w, unsigned h, double dx_=0.0, double dy_=0.0, double theta_=0.0): 
      dx(dx_), dy(dy_), theta(theta_)
  {
    set_size(w,h);
    //fill(0.0);
  }

  ~dbdet_kernel(){}

  //: recompute kernel with given subpixel shifts
  virtual void recompute_kernel(double dx_=0.0, double dy_=0.0, double theta=0.0)=0;

};

#endif // dbdet_kernel_h
