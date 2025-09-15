#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	// Swap chain should never outlive the render system.
	// Hence, we store a shared pointer to the render system to each graphics resource.
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice() noexcept
{
	// Dereferencing unique ptr returns raw non-null reference
	return *m_graphicsDevice;
}

void dx3d::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1, 0, 0, 1 });

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);
	swapChain.present();
}
