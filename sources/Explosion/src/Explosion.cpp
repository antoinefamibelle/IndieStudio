/*
** EPITECH PROJECT, 2020
** GitLabIndie
** File description:
** Explosion
*/

#include "Explosion.hpp"

Explosion::Explosion(IrrlichtDevice *device, int x, int y, vector3df dir, int range)
{
    _sceneManager = device->getSceneManager();
    _videoDriver = device->getVideoDriver();
    _particleSystem = _sceneManager->addParticleSystemSceneNode(false);
    _particleEmitter = _particleSystem->createBoxEmitter(aabbox3d<f32>
                                                (50 * (y - 6) - 10, 30 - 10, -50 * (x - 5) + 50 - 10,
                                                50 * (y - 6) + 10, 30 + 10, -50 * (x - 5) + 50 + 10),
                                                dir, 1500, 1500,
                                                SColor(0, 255, 255, 255), SColor(0, 255, 255, 255),
                                                range * 100, range * 100,
                                                0, dimension2df(8, 8), dimension2df(15, 15));
    _particleSystem->setEmitter(_particleEmitter);
    _particleEmitter->drop();
    _particleAffector = _particleSystem->createFadeOutParticleAffector(SColor(0, 0, 0, 0), 50);
    _particleSystem->addAffector(_particleAffector);
    _particleAffector->drop();
    _particleSystem->setMaterialFlag(EMF_LIGHTING, false);
    _particleSystem->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    _particleSystem->setMaterialTexture(0, _videoDriver->getTexture("./Assets/3d/fire.bmp"));
    _particleSystem->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}

Explosion::~Explosion()
{
    _particleSystem->remove();
}