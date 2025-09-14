#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/RenderSystem.h>

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	// Swap chain should never outlive the render system.
	// Hence, we store a shared pointer to the render system to each graphics resource.
	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

RenderSystem& dx3d::GraphicsEngine::getRenderSystem() const noexcept
{
	// Dereferencing unique ptr returns raw non-null reference
	return *m_renderSystem;
}
