#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d
{
	class SwapChain final: public GraphicsResource
	{
	public:
		SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc);
		Rect getSize() const noexcept;

		void present(bool vsync = false);
	private:
		void reloadBuffers();
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv{};
		Rect m_size{};

		// C++ feature: "Friend" classes to bypass encapsulation
		// in scenarios, where two or more classes are tightly coupled.
		friend class DeviceContext;
	};
}

