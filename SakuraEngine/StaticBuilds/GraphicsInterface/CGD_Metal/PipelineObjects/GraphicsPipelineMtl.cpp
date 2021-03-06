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
 * @Date: 2020-05-02 18:09:18
 * @LastEditTime: 2020-05-03 12:51:35
 */
#include "GraphicsPipelineMtl.h"
#include "../ResourceObjects/ShaderMtl.h"
#include "../CGDMetal.hpp"

using namespace Sakura::Graphics::Mtl;

GraphicsPipelineMtl::GraphicsPipelineMtl(const GraphicsPipelineCreateInfo& info,
    const RenderPassMtl& prog, const CGDMtl& _cgd)
    :cgd(_cgd), pass(prog)
{
    mtlpp::RenderPipelineDescriptor renderPipelineDesc;
    for(auto i = 0u; i < info.shaderStages.size(); i++)
    {   
        ShaderMtl* shaderMtl = (ShaderMtl*)info.shaderStages[i].GetShader();
        mtlpp::Function function 
            = shaderMtl->shaderFunctions[info.shaderStages[i].GetEntry()];
        switch (info.shaderStages[i].GetStage())
        {
        case ShaderStageFlags::VertexStage:
            renderPipelineDesc.SetVertexFunction(function);
            break;
        case ShaderStageFlags::PixelStage:
            renderPipelineDesc.SetFragmentFunction(function);
        default:
            CGDMtl::error("CGDMtl: Shader stage not supported in metal!");
            break;
        }
    }
    renderPipelineState
            = cgd.entity.device.NewRenderPipelineState(renderPipelineDesc, nullptr);
}

GraphicsPipelineMtl::~GraphicsPipelineMtl()
{
    
}