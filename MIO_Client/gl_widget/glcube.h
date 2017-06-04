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
    /**
     * @brief fill - just the data. vertice coordinate and then normal.
     * @remark we use the normal as a coloring.
     */
    void fill() {
        ///@remark Y up.
        m_data = {
                    -1.0f,-1.0f,-1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f,-1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,   -1.0f, 0.0f, 0.0f, // Left Side
                    -1.0f,-1.0f,-1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,   -1.0f, 0.0f, 0.0f, // Left Side
                     1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f, // Back Side
                     1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f,
                     1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f, // Bottom Side
                     1.0f, 1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                     1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f, 0.0f,-1.0f, // Back Side
                     1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f, 1.0f,    0.0f,-1.0f, 0.0f,
                    -1.0f,-1.0f,-1.0f,    0.0f,-1.0f, 0.0f, // Bottom Side
                    -1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                    -1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                     1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f, // Front Side
                     1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f,-1.0f,-1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f, 1.0f,-1.0f,    1.0f, 0.0f, 0.0f, // Right Side
                     1.0f,-1.0f,-1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 0.0f,
                     1.0f,-1.0f, 1.0f,    1.0f, 0.0f, 0.0f, // Right Side
                     1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
                     1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f, // Top Side
                     1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f,-1.0f,    0.0f, 1.0f, 0.0f,
                    -1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f, // Top Side
                     1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                    -1.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
                     1.0f,-1.0f, 1.0f,    0.0f, 0.0f, 1.0f, // Front Side

        };
    }

};

#endif // GLCUBE_H
