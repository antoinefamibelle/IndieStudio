/*
** EPITECH PROJECT, 2020
** GitLabIndie
** File description:
** Explosion
*/

#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace video;
using namespace core;

class Explosion {
    public:
        Explosion(IrrlichtDevice *, int , int, vector3df, int);
        ~Explosion();

    private:
        ISceneManager *_sceneManager;
        IVideoDriver *_videoDriver;
        IParticleEmitter *_particleEmitter;
        IParticleAffector *_particleAffector;
        IParticleSystemSceneNode *_particleSystem;
};

#endif /* !EXPLOSION_HPP_ */