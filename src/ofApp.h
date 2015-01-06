/*
 ---------------------------------------------
 GPU LUT IN OPENFRAMEWORKS
 ---------------------------------------------
 BY HUBRIS [http://cargocollective.com/hubris]
 [http://github.com/youandhubris]
 PORTO á DECEMBER 2014
 ---------------------------------------------
 EXAMPLE
 ---------------------------------------------
 */

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    // Shader
    ofShader lutFilter;
    ofPlanePrimitive plane;
    
    // LUT
    GLuint texture3D;
    int LUTsize = 32;
    string LUTpath;
    struct RGB { float r, g, b; };
    
    // Video
    ofVideoGrabber  webCam;
    
};
