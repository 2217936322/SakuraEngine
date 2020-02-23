/*
 * @This File is Part of Sakura by SaeruHikari: 
 * @Descripttion: CopyRight SaeruHikari
 * @Version: 0.1.0
 * @Author: SaeruHikari
 * @Date: 2020-02-02 12:58:52
 * @LastEditors: SaeruHikari
 * @LastEditTime: 2020-02-23 21:39:18
 */
#pragma once
#include "Core/CoreMinimal/SInterface.h"
#include "Core/CoreMinimal/SDefination.h"
#include "CommandObjects/CommandContext.h"

namespace Sakura::Graphics
{
    SInterface CGD
    {
        virtual ~CGD() = default;
        enum class TargetGraphicsInterface : std::uint32_t
        {
            CGD_TARGET_DIRECT3D12,
            CGD_TARGET_VULKAN,
            CGD_TARGET_NUMS
        };
        SAKURA_API static void Initialize(TargetGraphicsInterface targetGI);
        virtual void Render(void) = 0;
        virtual void Destroy(void) = 0;
        SAKURA_API static CGD* GetCGD(void)
        {
            ASSERT_RUNTIME(eCGD != nullptr);
            return eCGD;
        }
        SAKURA_API static ContextManager* GetContextManager(void)
        {
            ASSERT_RUNTIME(GetCGD()->m_ContextManager.get() != nullptr);
            return GetCGD()->m_ContextManager.get();
        }
    protected:
        SAKURA_API static Sakura::Graphics::CGD* eCGD;
        std::unique_ptr<ContextManager> m_ContextManager;
    };
}