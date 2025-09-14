#include <DX3D/Graphics/SwapChain.h>

dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc):
	GraphicsResource(gDesc)
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};

	// Various included headers may include custom MAX definitions.
	// Thus: Disabled MAX macro by defining NOMINMAX in properties.

	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// 8 bit RGBA channels
	dxgiDesc.BufferCount = 2;									// Two back buffers
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		// Use buffer as render target

	dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;								// No anti-aliasing
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;		// Not copied but swapped
	dxgiDesc.Windowed = TRUE;

	DX3DGraphicsLogErrorAndThrow(m_factory.CreateSwapChain(&m_device, &dxgiDesc, &m_swapChain),
		"CreateSwapChain failed.");
}
