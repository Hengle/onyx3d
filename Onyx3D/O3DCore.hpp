//
//  O3DCore.hpp
//  Onyx3D
//
//  Created by Josue Candela Perdomo on 18/04/2017.
//  Copyright © 2017 Josue Candela. All rights reserved.
//

#ifndef O3DCore_hpp
#define O3DCore_hpp

#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/vec2.hpp>

#include "O3DRender.hpp"
#include "O3DResources.hpp"
#include "O3DUI.hpp"

namespace o3d {
    
    class O3DCore{
    
    public:
        
        ~O3DCore();
        
        int init(GLint width, GLint height, const char* window_name);
        int init(GLint width, GLint height);
        bool running();
        void update();
        void render();
        void terminate();
        void errorCallback(int error, const char* description);
        
        float getTime(){ return glfwGetTime(); };
        float getElapsedTime(){ return m_elapsedTime; };
        float getFPS(){ return m_fps; };
        
        O3DCore(O3DCore const&)             = delete;
        void operator=(O3DCore const&)      = delete;
        
        static O3DCore& getInstance(){
            static O3DCore instance;
            return instance;
        }

        
        const glm::vec2& getScreenSize() { return m_screenSize; }
        GLFWwindow * getWindow() { return m_window; }
        O3DResources& getResources() { return m_resources; }
        O3DRender& getRenderer(){ return m_render; }
        O3DUI& getUI(){ return m_ui; }
        
        void setFocused(bool focus) { m_focused = focus; }
        bool isFocused(){ return m_focused; }
    private:
        O3DResources m_resources;
        O3DRender m_render;
        O3DUI m_ui;
        
        glm::vec2 m_screenSize;
        GLFWwindow * m_window;
        
        float m_elapsedTime;
        float m_latestTime;
        float m_fpsFrames = 0;
        float m_fpsTime = 0;
        float m_fps = 0;
        bool m_focused = true;
        
        O3DCore();

    };

    
    inline O3DCore &O3D() {
        return O3DCore::getInstance();
    }

    static void window_focus_callback(GLFWwindow* window, int focused)
    {
        O3D().setFocused(focused == GLFW_TRUE);
    }
}




#endif /* O3DCore_hpp */
