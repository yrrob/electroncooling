#ifndef RING_H
#define RING_H

#include <cassert>
#include <string>
#include <vector>
#include "beam.h"
#include "constants.h"

using std::vector;

//enum class ShapeList {uniformCylinder=1, GaussianBunch=2, GaussianCylinder=3, uniformCylinderSlope=4,
//                      uniformCylinderBunch, darkCurrent};

class Lattice{
    vector<double> s_;
    vector<double> betx_;
    vector<double> alfx_;
    vector<double> mux_;
    vector<double> dx_;
    vector<double> dpx_;
    vector<double> bety_;
    vector<double> alfy_;
    vector<double> muy_;
    vector<double> dy_;
    vector<double> dpy_;
    vector<double> l_element_;
    int n_element_;
    double circ_;
 public:
    double s(int i){return s_.at(i);}
    double betx(int i){return betx_.at(i);}
    double alfx(int i){return alfx_.at(i);}
    double mux(int i){return mux_.at(i);}
    double dx(int i){return dx_.at(i);}
    double dpx(int i){return dpx_.at(i);}
    double bety(int i){return bety_.at(i);}
    double alfy(int i){return alfy_.at(i);}
    double muy(int i){return muy_.at(i);}
    double dy(int i){return dy_.at(i);}
    double dpy(int i){return dpy_.at(i);}
    double n_element(){return n_element_;}
    double l_element(int i){return l_element_.at(i);}
    double circ(){return circ_;}
    Lattice(std::string filename);

};

class Ring{
    double beta_s_ = 0;         //Synchrotron function, use to calculate rms bunch length from momentum spread
    double circ_ = 0;        //Circumference of the ring;
 public:
    Beam *beam_;
    Lattice *lattice_;
    double beta_s(){assert(beam_->bunched()); return beta_s_;}
    double circ(){return circ_;}
    Ring(double circ, Beam &beam_defined);
    Ring(Lattice &lattice_defined, Beam &beam_defined);
};
#endif // RING_H
