#ifndef GLPLANE_H
#define GLPLANE_H
#include"glshape.h"

class glplane: public glshape{
public:
    /**
     * @brief glcube - constructor.
     * @todo  change the constructor to be in glshape
     */
    glplane()
    {

        fill();
    }

private:
    /**
     * @brief fill - just the data. vertice coordinate and then normal.
     * @remark we use the normal as a coloring.
     * @todo this should be a virtual function.
     */
    void fill() {
        ///@remark Y up.
        m_data = {

                     100.0f, 0.0f, 100.0f,    0.0f, 1.0f, 0.0f,
                    -100.0f, 0.0f,-100.0f,    0.0f, 1.0f, 0.0f,
                    -100.0f, 0.0f, 100.0f,    0.0f, 1.0f, 0.0f, // Top Side
                     100.0f, 0.0f, 100.0f,    0.0f, 1.0f, 0.0f,
                    -100.0f, 0.0f,-100.0f,    0.0f, 1.0f, 0.0f,
                     100.0f, 0.0f,-100.0f,    0.0f, 1.0f, 0.0f, // Top Side
        };
    }

};

#endif // GLPLANE_H
