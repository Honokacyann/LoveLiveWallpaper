#include "SpriteRenderer.h"

#include "Graphics.h"
#include "Sprite.h"
#include "Transform.h"

#include <d2d1effects_2.h>

using ::std::shared_ptr;
using ::std::make_shared;

namespace LLWP
{
    SpriteRenderer::SpriteRenderer(GameObject& o, shared_ptr<Sprite>&& s) :
        Renderer(o),
        _sprite(s)
    {
    }

    SpriteRenderer::SpriteRenderer(GameObject& o, const wchar_t* path) :
        Renderer(o),
        _sprite(make_shared<Sprite>(path))
    {}

    SpriteRenderer::~SpriteRenderer()
    {
    }

    Sprite& SpriteRenderer::sprite()
    {
        return *_sprite;
    }

    void SpriteRenderer::Render()
    {
    }
}