// =============================================================================
//
// Copyright (c) 2014-2015 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include "ofMain.h"
#include "ofxOpenCv.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber videoGrabber0;
    ofVideoGrabber videoGrabber1;
    
    int cameraWidth0=640;
    int cameraHeight0=480;
    
    
    uint64_t interval = 300; // 12 ms.
    uint64_t lastUpdate = 0;
    ofPixels pixels0;
   
    int cameraWidth1=640;
    int cameraHeight1=480;
    
    
    
      ofPixels pixels1;
    ofTexture texture0;
    ofTexture texture1;


    ofxCvColorImage rgb0,hsb0;
    ofxCvColorImage rgb1,hsb1;
    
    ofxCvGrayscaleImage hue0,sat0,bri0,filtered0;
    ofxCvGrayscaleImage hue1,sat1,bri1,filtered1;
    ofxCvContourFinder contours;

    
    
    //========================================================================infrared=======================
    ofFloatColor getColor(double v, double vmin,double vmax)
    {
        ofFloatColor c = {1.0,1.0,1.0}; // white
        double dv;
        
        if (v < vmin)
            v = vmin;
        if (v > vmax)
            v = vmax;
        dv = vmax - vmin;
        
        if (v < (vmin + 0.25 * dv)) {
            c.r = 0;
            c.g = 4 * (v - vmin) / dv;
        } else if (v < (vmin + 0.5 * dv)) {
            c.r = 0;
            c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
        } else if (v < (vmin + 0.75 * dv)) {
            c.r = 4 * (v - vmin - 0.5 * dv) / dv;
            c.b = 0;
        } else {
            c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
            c.b = 0;
        }
        
        return(c);
    }
//======================================================================================================================

    
};
