//
//  main.cpp
//  thelasterror
//
//  Created by Evan Walsh on 1/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include <GL/glfw.h>

double calcFPS();

double calcFPS(double theTimeInterval = 1.0, std::string theWindowTitle = "NONE")
{
	// Static values which only get initialised the first time the function runs
	static double t0Value       = glfwGetTime(); // Set the initial time to now
	static int    fpsFrameCount = 0;             // Set the initial FPS frame count to 0
	static double fps           = 0.0;           // Set the initial FPS value to 0.0
    
	// Get the current time in seconds since the program started (non-static, so executed every time)
	double currentTime = glfwGetTime();
    
	// Ensure the time interval between FPS checks is sane (low cap = 0.1s, high-cap = 10.0s)
	// Negative numbers are invalid, 10 fps checks per second at most, 1 every 10 secs at least.
	if (theTimeInterval < 0.1)
	{
		theTimeInterval = 0.1;
	}
	if (theTimeInterval > 10.0)
	{
		theTimeInterval = 10.0;
	}
    
	// Calculate and display the FPS every specified time interval
	if ((currentTime - t0Value) > theTimeInterval)
	{
		// Calculate the FPS as the number of frames divided by the interval in seconds
		fps = (double)fpsFrameCount / (currentTime - t0Value);
        
		// If the user specified a window title to append the FPS value to...
		if (theWindowTitle != "NONE")
		{
			// Convert the fps value into a string using an output stringstream
			std::ostringstream stream;
			stream << fps;
			std::string fpsString = stream.str();
            
			// Append the FPS value to the window title details
			theWindowTitle += " | FPS: " + fpsString;
            
			// Convert the new window title to a c_str and set it
			const char* pszConstString = theWindowTitle.c_str();
			glfwSetWindowTitle(pszConstString);
		}
		else // If the user didn't specify a window to append the FPS to then output the FPS to the console
		{
			std::cout << "FPS: " << fps << std::endl;
		}
        
		// Reset the FPS frame counter and set the initial time to be now
		fpsFrameCount = 0;
		t0Value = glfwGetTime();
	}
	else // FPS calculation time interval hasn't elapsed yet? Simply increment the FPS frame counter
	{
		fpsFrameCount++;
	}
    
	// Return the current FPS - doesn't have to be used if you don't want it!
	return fps;
}

int main(int argc, const char * argv[])
{
    
    const int   windowWidth = 960,
    windowHeight = 600;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    if (!glfwOpenWindow(windowWidth, windowHeight, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
        return -1;
    
    glfwSetWindowTitle("The Last Error");
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = ((float)windowHeight) / windowWidth;
    glFrustum(.5, -.5, -.5 * aspectRatio, .5 * aspectRatio, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glfwSwapInterval(0); // Turn off vsync
    
    /* Loop until the user closes the window */
    double lastTime = glfwGetTime();
    while (glfwGetWindowParam(GLFW_OPENED))
    {
        double currentTime = glfwGetTime(),
        delta = (currentTime - lastTime);
        lastTime = currentTime;
        
        printf("Delta: %f\n", delta);
        
        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // swap back and front buffers
        glfwSwapBuffers();
    }
    
    return 0;
}