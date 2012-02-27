#ifndef _CSTONEDWEASEL_H_
#define _CSTONEDWEASEL_H_

#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class CStonedWeasel {
    public:
        CStonedWeasel();

    public:
        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event* event);
        void OnLoop();
        void OnRender();
        void OnCleanup();

    private:
        SDL_Surface* m_pDisplay;
        bool m_bRunning;
};

#endif