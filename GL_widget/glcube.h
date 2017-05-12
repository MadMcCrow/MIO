#ifndef GLCUBE_H
#define GLCUBE_H
#include "glshape.h"

/**
* @brief The glcube class - a nice cube for the cold winter days
*/
class glcube : public glshape
{
public:
    glcube()
    {

        fill();
    }

private:
    void fill() {
        // this whole thing is sub-optimal so why the f*** I wouldn't just lay all the vertices and normal like that.
        ///@remark Y up.
        m_data = {
                    -1.0f,-1.0f,-1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f,-1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,                   // Left Side
                    -1.0f,-1.0f,-1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,   -1.0f, 0.0f, 0.0f,                   // Left Side
                     1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f,  // Back Side
                     1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f,
                     1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f,  // Bottom Side
                     1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                     1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f,  // Back Side
                     1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f,  // Bottom Side
                    -1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                    -1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                     1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f,   // Front Side
                     1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f,-1.0f,-1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f, 1.0f,-1.0f,    1.0f, 0.0f, 0.0f,   // Right Side
                     1.0f,-1.0f,-1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f,-1.0f, 1.0f,    1.0f, 0.0f, 0.0f,   // Right Side
                     1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
                     1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f,  // Top Side
                     1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f, // Top Side
                     1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                    -1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                     1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f,  // Front Side

        };
    }

};

#endif // GLCUBE_H
