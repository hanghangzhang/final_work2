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


#include "ofApp.h"
#include "ofxPS3EyeGrabber.h"


void ofApp::setup()

{
     videoGrabber0.setVerbose(true);
     videoGrabber1.setVerbose(true);
    // Set the video grabber to the ofxPS3EyeGrabber.
    videoGrabber0.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    videoGrabber0.setDeviceID(0);
    //    vidGrabber0.setup(640, 480);
    videoGrabber0.setup(cameraWidth0, cameraHeight0);
    
    videoGrabber1.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    videoGrabber1.setDeviceID(1);
    //    vidGrabber1.setup(640, 480);
    videoGrabber1.setup(cameraWidth1, cameraHeight1);
//    pixels0.allocate(320, 240, OF_PIXELS_RGB);
    
    
}


void ofApp::update()
{
    videoGrabber0.update();
    videoGrabber1.update();
    
    uint64_t now = ofGetElapsedTimeMillis();
    
    if (now > (lastUpdate + interval))
    {
        lastUpdate = now;
        pixels0 = videoGrabber0.getPixels();
        pixels1 = videoGrabber1.getPixels();
    }
    

    
    
    if(videoGrabber0.isFrameNew()){
        
//        
//        //copy webcam pixels to rgb image
//        rgb0.setFromPixels( pixels0, cameraWidth0,cameraHeight0);
//        
//        //mirror horizontal
//        rgb0.mirror(false, true);
//        
//        //duplicate rgb
//        hsb0 = rgb0;
//        
////        //convert to hsb
//        hsb0.convertRgbToHsv();
////
////        //store the three channels as grayscale images
//        hsb0.convertToGrayscalePlanarImages(sat0, hue0, bri0);
//        ofPixels pixels0hsb=hsb0.getPixels();

        
//        pixels0 = videoGrabber0.getPixels();
        
        for(int x0 =0; x0< cameraWidth0; x0++){
            
            for(int y0 =0; y0<cameraHeight0; y0++){
                //                int rArrayIndex = (y*W*3) + (x*3);
                //                int gArrayIndex = (y*W*3) + (x*3) + 1;
                //                int bArrayIndex = (y*W*3) + (x*3) + 2;
                //                unsigned char redValueAtXY   = buffer[rArrayIndex];
                //                unsigned char greenValueAtXY = buffer[gArrayIndex];
                //                unsigned char blueValueAtXY  = buffer[bArrayIndex];
                //                redValueAtXY =0;
                
                //                ofColor originalColor = pixels.getColor(x, y);
                //                originalColor.r = 0;
                //                pixels.setColor(x, y, originalColor);
                
                
                
                ofColor originalColor0 = pixels0.getColor(x0, y0);
                float brightness0 = originalColor0.getBrightness();
                float brightness01 = originalColor0.getHue();
                float brightness02 = originalColor0.getSaturation();
                
                ofFloatColor mappedColor0 = getColor(brightness01,0,brightness0);
                pixels0.setColor(x0, y0, mappedColor0);
                
                
                
            }
            
        }
        
//        
//        texture0.loadData(pixels0);
        
        
        for(int x1 =0; x1< cameraWidth1; x1++){
            
            for(int y1 =0; y1<cameraHeight1; y1++){
                //                int rArrayIndex = (y*W*3) + (x*3);
                //                int gArrayIndex = (y*W*3) + (x*3) + 1;
                //                int bArrayIndex = (y*W*3) + (x*3) + 2;
                //                unsigned char redValueAtXY   = buffer[rArrayIndex];
                //                unsigned char greenValueAtXY = buffer[gArrayIndex];
                //                unsigned char blueValueAtXY  = buffer[bArrayIndex];
                //                redValueAtXY =0;
                
                //                ofColor originalColor = pixels.getColor(x, y);
                //                originalColor.r = 0;
                //                pixels.setColor(x, y, originalColor);
                
                
                
                ofColor originalColor1 = pixels1.getColor(x1, y1);
                float brightness1 = originalColor1.getBrightness();
                float brightness11 = originalColor1.getHue();
                float brightness12 = originalColor1.getSaturation();

                
                ofFloatColor mappedColor1 = getColor(brightness11,0,brightness1);
                pixels1.setColor(x1, y1, mappedColor1);
                
                
                
            }
            
        }

        
    }
    

}


void ofApp::draw()
{
    ofBackground(0);
//    ofSetColor(255);
//        videoGrabber0.draw(0, 0);
    ofPushMatrix();
    ofTranslate(50, 50);
    
    for (int i0 = 0; i0 < cameraHeight0; i0 += 5) {
        for (int j0= 0; j0 < cameraWidth0; j0 += 5) {
//            ofPixels pixelred0 = texture0.getPixel
            ofColor pixelColor0 = pixels0.getColor(j0, i0);
            
            
//            if (i > 40 && i < 100)
//            {
//                pixelColor0.lerp(ofColor(255, 255, 0), 0.1);
//            }
//            
            
            ofSetColor(pixelColor0);
            ofPath path0 = ofPath();
            path0.setColor(pixelColor0);
            path0.setFillColor(pixelColor0);
            
            float y0 = i0;
            float x0 = j0;
            
            if (i0 % 2 == 0)
            {
                x0 += 2.5;
            }
            
            path0.moveTo(x0, y0 - 5);
            path0.lineTo(x0 + 2.5, y0 - 2.5);
            path0.lineTo(x0 + 2.5, y0 + 2.5);
            path0.lineTo(x0, y0 + 5);
            path0.lineTo(x0 - 2.5, y0 + 2.5);
            path0.lineTo(x0 - 2.5, y0 - 2.5);
            path0.lineTo(x0 , y0 - 5);
            path0.close();
            path0.draw();
            
        }
        
    }
    ofPopMatrix();
//
//    vidGrabber0.getTexture().drawSubsection(0, 0, 0,
//                                            320, 240,
//                                            0, 0,
//                                            320, 240);
//    
    //    vidGrabber1.draw(640 + 100, 0);
    
//    videoGrabber1.draw(640 + 100, 0);
    ofPushMatrix();
    ofTranslate(cameraWidth0+50,50);
//
    
    for (int i1 = 0; i1 < cameraHeight1; i1 += 5) {
        for (int j1 = 0; j1 < cameraWidth1; j1 += 5) {
            ofColor pixelColor1 = pixels1.getColor(j1, i1);
            
            
            //            if (i > 40 && i < 100)
            //            {
            //                pixelColor0.lerp(ofColor(255, 255, 0), 0.1);
            //            }
            //
            
            ofSetColor(pixelColor1);
            ofPath path1 = ofPath();
            path1.setColor(pixelColor1);
            path1.setFillColor(pixelColor1);
            
            float y1 = i1;
            float x1 = j1;
            
            if (i1 % 2 == 0)
            {
                x1 += 2.5;
            }
            
            path1.moveTo(x1, y1 - 5);
            path1.lineTo(x1 + 2.5, y1 - 2.5);
            path1.lineTo(x1 + 3.5, y1 + 3.5);
            path1.lineTo(x1, y1 + 5);
            path1.lineTo(x1 - 2.5, y1 + 2.5);
            path1.lineTo(x1 - 2.5, y1 - 2.5);
            path1.lineTo(x1 , y1 - 5);
            path1.close();
            path1.draw();
            
        }
        
    }

    
    ofPopMatrix();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
