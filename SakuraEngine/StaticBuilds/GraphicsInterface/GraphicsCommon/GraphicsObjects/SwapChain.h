/*
 * @CopyRight: MIT License
 * Copyright (c) 2020 SaeruHikari
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THESOFTWARE.
 * 
 * 
 * @Description: 
 * @Version: 0.1.0
 * @Autor: SaeruHikari
 * @Date: 2020-03-04 21:41:05
 * @LastEditTime: 2020-03-06 00:53:11
 */
#pragma once
#include "Core/CoreMinimal/SInterface.h"
#include "Core/CoreMinimal/SDefination.h"
#include "../Format/PixelFormat.h"
#include "../Format/CommonFeatures.h"
#include <memory>
#include <vector>
#include "../ResourceObjects/Resource.h"
#include "../ResourceObjects/ResourceViews.h"

namespace Sakura::Graphics
{
    SInterface SwapChain
    {
        virtual ~SwapChain() {};
        virtual void GetExtent(uint32& width, uint32& height) = 0;
        const PixelFormat GetPixelFormat() const {return swapChainImageFormat;};
        void SetPixelFormat(const PixelFormat fmt){swapChainImageFormat=fmt;}
        uint32 swapChainCount = 2;
        std::vector<std::unique_ptr<GpuResource>> swapChainImages;
        std::vector<std::unique_ptr<ResourceView>> resourceViews;
    protected:
        PixelFormat swapChainImageFormat;
    };
}
