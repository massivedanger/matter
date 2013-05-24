//
//  Text.h
//  Massive
//
//  Created by Evan Walsh on 8/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Text__
#define __Massive__Text__

#include "../Utilities/Common.h"
#include "Actor.h"
#include <SFML/Graphics.hpp>

//#define MASSIVE_DEFAULT_FONT "Libraries/Meslo LG v1.2.1/MesloLGL-Regular.ttf"
#define MASSIVE_DEFAULT_FONT "/Users/evan/Library/Fonts/MesloLGS-Regular.ttf"

class Text : public Actor {
    
public:
    Text(
         String string = "",
         String fontPath = MASSIVE_DEFAULT_FONT,
         int size = 16
        );
    ~Text();
    
    virtual void Update(float dt);
    virtual void Draw();
    
    String GetString() { return _string; }
    void SetString(String string);
    
    sf::Font GetFont() { return _font; }
    void SetFont(sf::Font font);
    
    virtual void SetPosition(int x, int y);
    virtual void MovePosition(int x, int y);
    virtual sf::Vector2f GetPosition();
    
    virtual void SetRotation(float rotation);
    virtual void Rotate(float rotation);
    virtual float GetRotation();
    
    virtual void SetScale(float scaleX, float scaleY);
    virtual void Scale(float scaleX, float scaleY);
    virtual sf::Vector2f GetScale();
    
    virtual void SetOrigin(int x, int y);
    virtual sf::Vector2f GetOrigin();
    
private:
    String _string;
    String _fontPath;
    sf::Font _font;
    sf::Text _drawable;
};

#endif /* defined(__Massive__Text__) */
