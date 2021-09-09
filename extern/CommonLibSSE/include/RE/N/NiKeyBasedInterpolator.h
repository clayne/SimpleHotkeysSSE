#pragma once

#include "RE/N/NiAnimationKey.h"
#include "RE/N/NiInterpolator.h"

namespace RE
{
	class NiKeyBasedInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiKeyBasedInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiKeyBasedInterpolator;

		using KeyType = NiAnimationKey::KeyType;
		using KeyContent = NiAnimationKey::KeyContent;

		virtual ~NiKeyBasedInterpolator();  // 00

		// override (NiInterpolator)
		virtual const NiRTTI* GetRTTI() const override;                                         // 02
		virtual void          LoadBinary(NiStream& a_stream) override;                          // 18 - { NiInterpolator::LoadBinary(a_stream); }
		virtual void          LinkObject(NiStream& a_stream) override;                          // 19 - { NiInterpolator::LinkObject(a_stream); }
		virtual bool          RegisterStreamables(NiStream& a_stream) override;                 // 1A - { return NiInterpolator::RegisterStreamables(a_stream); }
		virtual void          SaveBinary(NiStream& a_stream) override;                          // 1B - { NiInterpolator::SaveBinary(a_stream); }
		virtual bool          IsEqual(NiObject* a_object) override;                             // 1C - { return NiInterpolator::IsEqual(a_stream); }
		virtual void          GetActiveTimeRange(float& a_start, float& a_end) const override;  // 32

		// add
		virtual std::uint16_t GetKeyChannelCount() const = 0;                      // 39
		virtual std::uint32_t GetKeyCount(std::uint16_t a_channel) const = 0;      // 3A
		virtual KeyType       GetKeyType(std::uint16_t a_channel) const = 0;       // 3C
		virtual KeyContent    GetKeyContent(std::uint16_t a_channel) const = 0;    // 3B
		virtual void*         GetKeyArray(std::uint16_t a_channel) const = 0;      // 3D
		virtual std::uint8_t  GetKeyStride(std::uint16_t a_channel) const = 0;     // 3E
		virtual bool          GetChannelPosed(std::uint16_t a_channel) const = 0;  // 3F
	};
	static_assert(sizeof(NiKeyBasedInterpolator) == 0x18);
}
