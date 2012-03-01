#ifndef _CVERTEX_H_
#define _CVERTEX_H_

class CVertex {
 public:
    CVertex(float fX, float fY, float FZ);
    ~CVertex();

    union { // does this make any sense?
        struct {
            float x, y, z;
        };
        float xyz[3];
    };

    void set(float fX, float fY, float fZ);
    float const * getVertex3fv() const;
};

#endif
