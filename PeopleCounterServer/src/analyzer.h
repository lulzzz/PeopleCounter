#pragma once

#include "ofMain.h"
#include "gui.h"
#include "defines.h"

struct blob_data {
	int bid;
	float x;
	float y;
    float w;
    float h;
    
    int birth;
    bool isCounted;
    float birthX;
    float birthY;
    bool inFrame;
    
   vector<int> childrenBid;
    bool foundInThisFrame;
};


class Filesaver;

class Analyzer {
public:
	void setup(Gui * gui, Filesaver * filesaverRef);
	void update();
	void debugDraw();
	
    Gui * gui;
    Filesaver * filesaver;
    
	vector< blob_data > blobData[NUM_CLIENTS];
    
    void markNewFrame(int client);
    void addBlobData(blob_data newData, int client);
    
    int count;
    int addedCount;
    
    int currentCount;
    
    int hourCount();
    
    vector<blob_data> combinedBlobs;
    
    float onePersonArea;
    
};