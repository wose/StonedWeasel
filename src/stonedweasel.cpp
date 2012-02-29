#include "stonedweasel.h"

////////////////////////////////////////////////////////////////////////////////
CStonedWeasel::CStonedWeasel() {
    m_bRunning = true;
    m_pDisplay = NULL;
}

////////////////////////////////////////////////////////////////////////////////
int CStonedWeasel::OnExecute() {
    if(!OnInit())
        return -1;
    
    SDL_Event event;

    while(m_bRunning) {
        while(SDL_PollEvent(&event))
            OnEvent(&event);
        
        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
bool CStonedWeasel::OnInit() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    SDL_WM_SetCaption("Stoned Weasel", 0);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,     32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    m_pDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
    if(!m_pDisplay)
        return false;

    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 640, 480, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();

    return true;
}

////////////////////////////////////////////////////////////////////////////////
void CStonedWeasel::OnEvent(SDL_Event* event) {
    switch(event->type) {
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym) {
                case SDLK_ESCAPE:
                    m_bRunning = false;
                    break;
                default:
                    break;
            }

            break;

        case SDL_KEYUP:
            break;

        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_MOUSEBUTTONUP:
            break;

        case SDL_QUIT:
            m_bRunning = false;
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
void CStonedWeasel::OnLoop() {
    
}

////////////////////////////////////////////////////////////////////////////////
void CStonedWeasel::OnRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
    glEnd();

    SDL_GL_SwapBuffers();
}

////////////////////////////////////////////////////////////////////////////////
void CStonedWeasel::OnCleanup() {
    SDL_Quit();
}
