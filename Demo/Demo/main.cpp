//
//  main.cpp
//  Onyx3D
//
//  Created by Josue Candela Perdomo on 17/04/2017.
//  Copyright (c) 2017 Josue Candela. All rights reserved.
//

#include <iostream>
#include "O3DCore.hpp"
#include "O3DInput.hpp"
#include "O3DCamera.hpp"
#include "O3DGameObject.hpp"
#include "O3DScene.hpp"
#include "O3DSceneLoader.hpp"
#include "O3DUILoader.hpp"
#include "O3DModel.hpp"

#include "O3DTextRenderer.hpp"

#include <GL/glew.h>

    

const GLint WIDTH = 1024;
const GLint HEIGHT = 768;

using namespace o3d;

int main() {
    
    if (!O3D().init(WIDTH, HEIGHT, "Onyx3D Engine")){
        std::cout << "Failed to initialize Onyx3D" << std::endl;
        return -1;
    }
    
    
    std::string scene_path = "resources/scenes/test_model.lua";
    //std::string scene_path = "resources/scenes/demo_dungeon.lua";
    
    O3DUILoader::load("resources/ui/test.lua");
    
    Scene_ptr scene = O3DSceneLoader::load(scene_path.c_str());
    Camera_ptr camera = scene->getObjectById<O3DCamera>("main_camera");
    GameObject_ptr pivot = scene->getObjectById<O3DGameObject>("pivot");
    
    
    
    
    //Shader_ptr font_s = std::make_shared<O3DShader>("resources/shaders/text.vert","resources/shaders/text.frag");
    //O3DTextRenderer tr;
    //tr.setFont(font);
    //glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
    
    
    bool wasFocused = true;
    float camspeed= 0;
    while(O3D().running()){
        
        // Camera movement
        
        if (O3DInput::isKeyPressed(Keys::W))
        camera->translate(glm::vec3(0,0,-0.05));
        if (O3DInput::isKeyPressed(Keys::S))
        camera->translate(glm::vec3(0,0,0.05));
        if (O3DInput::isKeyPressed(Keys::A))
        camspeed -= 0.1f;
        if (O3DInput::isKeyPressed(Keys::D))
        camspeed += 0.1f;
        if (O3DInput::isKeyPressed(Keys::ArrowUp))
        camera->translate(glm::vec3(0,0.05,0));
        if (O3DInput::isKeyPressed(Keys::ArrowDown))
        camera->translate(glm::vec3(0,-0.05,0));
        if (O3DInput::isKeyPressed(Keys::ArrowRight))
        camera->translate(glm::vec3(0.01,0,0));
        if (O3DInput::isKeyPressed(Keys::ArrowLeft))
        camera->translate(glm::vec3(-0.01,0,0));
        
        camera->rotate(glm::vec3(0,camspeed,0));
        if (camspeed>0)
        camspeed-=0.01f;
        if (camspeed<0)
        camspeed+=0.01f;
        if (O3DInput::isKeyPressed(Keys::Numpad_4))
        pivot->rotate(glm::vec3(0,1,0));
        if (O3DInput::isKeyPressed(Keys::Numpad_6))
        pivot->rotate(glm::vec3(0,-1,0));
        
        /*
         if (O3DInput::isKeyPressed(Keys::Numpad_7))
         go->getTransform()->translate(glm::vec3(0,-0.1,0));
         if (O3DInput::isKeyPressed(Keys::Numpad_1))
         go->getTransform()->translate(glm::vec3(0,0.1,0));
         //if (O3DInput::isKeyPressed(Keys::Numpad_9))*/
        
        
        
        O3D().update();
        
        
        
        
        if (O3D().isFocused()){
            O3D().render();
            
            
            if (!wasFocused){
                camspeed = 0;
                glm::vec3 prev_cam_pos = camera->getPosition();
                glm::vec3 prev_cam_rot = camera->getRotation();
                
                O3DUILoader::load("../../../../../../Onyx3D/resources/ui/test.lua");
                
                scene = O3DSceneLoader::load(("../../../../../../Onyx3D/" + scene_path).c_str(), true, false);
                camera = scene->getObjectById<O3DCamera>("main_camera");
                camera->setPosition(prev_cam_pos);
                camera->setRotation(prev_cam_rot);
                
                pivot = scene->getObjectById<O3DGameObject>("pivot");
                wasFocused = true;
            }
        }else{
            wasFocused = false;
        }
        
    }
    
    O3D().terminate();
    
    return 1;
}
